#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, _src, _tar, depth = 0, components = 1;
	scanf("%d", &n);
	map<int, set<int> > edges;
	set<int> roots, unvisited, _unvisited, visited;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &_src, &_tar);
		edges[_src].insert(_tar);
		edges[_tar].insert(_src);
		unvisited.insert(i);
	}
	unvisited.insert(n);
	set<set<int> > singles;
	for (int i = 1; i <= n; i++) {
		if (visited.find(i) == visited.end()) {
			if (edges[i].size() == 1) {
				set<int> single;
				single.insert(i);
				int j = *edges[i].begin();
				for (auto it = edges[j].begin(); it != edges[j].end(); it++) {
					if (edges[*it].size() == 1) {
						single.insert(*it);
						visited.insert(*it);
					}
				}
				singles.insert(single);
			}
		}
	}
	if (singles.empty()) {
		set<int> single;
		single.insert(1);
		singles.insert(single);
	}
	for (auto i = singles.begin(); i != singles.end(); i++) {
		queue<int> q1, q2;
		int _depth = 0;
		_unvisited = unvisited;
		q1.push(*i->begin());
		_unvisited.erase(*i->begin());
		while (!q1.empty()) {
			while(!q1.empty()) {
				int _tmp = q1.front();
				q1.pop();
				for (auto it = edges[_tmp].begin(); it != edges[_tmp].end(); it++) {
					if (_unvisited.find(*it) != _unvisited.end()) {
						q2.push(*it);
						_unvisited.erase(*it);
					}
				}
			}
			swap(q1, q2);
			_depth += 1;
		}
		if (!_unvisited.empty()) {
			while (!_unvisited.empty()) {
				components += 1;
				int _tmp = *_unvisited.begin();
				q1.push(_tmp);
				_unvisited.erase(_tmp);
				while (!q1.empty()) {
					while(!q1.empty()) {
						_tmp = q1.front();
						q1.pop();
						for (auto it = edges[_tmp].begin(); it != edges[_tmp].end(); it++) {
							if (_unvisited.find(*it) != _unvisited.end()) {
								q2.push(*it);
								_unvisited.erase(*it);
							}
						}
					}
					swap(q1, q2);
				}
			}
			break;
		}
		if (_depth >= depth) {
			if (_depth > depth) {
				depth = _depth;
				roots.clear();
			}
			for (auto j = i->begin(); j != i->end(); j++) {
				roots.insert(*j);
			}
		}
	}
	if (components != 1) {
		printf("Error: %d components\n", components);
	} else {
		for (auto it = roots.begin(); it != roots.end(); it++) {
			printf("%d\n", *it);
		}
	}
	return 0;
}

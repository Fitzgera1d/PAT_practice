#include <bits/stdc++.h>
using namespace std;

const int MAX = 99999999;

int main() {
	int n, m, start, dest, _c1, _c2, _dist, _cost, visit;
	map<int, map<int, vector<int> > > maps;
	map<int, vector<int> > dists;
	set<int> visited;
	scanf("%d%d%d%d", &n, &m, &start, &dest);
	dists[dest] = {MAX, MAX, start};
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &_c1, &_c2, &_dist, &_cost);
		if (_c1 == start || _c2 == start) {
			dists[_c1 == start ? _c2 : _c1] = {_dist, _cost, start};
		} else {
			maps[_c1][_c2] = {_dist, _cost};
			maps[_c2][_c1] = {_dist, _cost};
		}
	}
	do {
		visit = dest;
		for (int i = 0; i < n; i++) {
			if (visited.find(i) != visited.end() ) { continue; }
			if (dists.find(i) == dists.end() ) { continue; }
			if (dists[i][0] < dists[visit][0]) {
				visit = i;
			} else if (dists[i][0] == dists[visit][0] && dists[i][1] < dists[visit][1]) {
				visit = i;
			}
		}
		for (auto it = maps[visit].begin(); it != maps[visit].end(); it++) {
			if (dists.find(it->first) == dists.end()) {
				dists[it->first].resize(3);
				dists[it->first][0] = dists[visit][0] + it->second[0];
				dists[it->first][1] = dists[visit][1] + it->second[1];
				dists[it->first][2] = visit;
			} else if (dists[it->first][0] > (dists[visit][0] + it->second[0])) {
				dists[it->first][0] = dists[visit][0] + it->second[0];
				dists[it->first][1] = dists[visit][1] + it->second[1];
				dists[it->first][2] = visit;
			} else if (dists[it->first][0] == (dists[visit][0] + it->second[0]) && (dists[it->first][1] > (dists[visit][1] + it->second[1]))) {
				dists[it->first][1] = dists[visit][1] + it->second[1];
				dists[it->first][2] = visit;
			}
		}
		visited.insert(visit);
		
	} while (visit != dest);
	stack<int> path;
	while (visit != start) {
		path.push(visit);
		visit = dists[visit][2];
	}
	path.push(start);
	while (!path.empty()) {
		printf("%d ", path.top());
		path.pop();
	}
	printf("%d %d\n", dists[dest][0], dists[dest][1]);
	return 0;
}

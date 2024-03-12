#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, _score, _base, count = 0;
	char _id[20];
	scanf("%d", &n);
	map<int, set<string>, greater<int> > scores[n+1];
	map<int, int, greater<int> > ranks[n+1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		count += k;
		for (int j = 0; j < k; j++) {
			scanf("%s %d", _id, &_score);
			scores[i][_score].insert(string(_id));
			scores[0][_score].insert(string(_id));
		}
	}
	for (int i = 0; i <= n; i++) {
		_base = 0;
		for (map<int, set<string> >::iterator it = scores[i].begin(); it != scores[i].end(); it++) {
			ranks[i][it->first] = _base + 1;
			_base += it->second.size();
		}
	}
	printf("%d\n", count);
	for (auto it = scores[0].begin(); it != scores[0].end(); it++) {
		for (auto it1 = it->second.begin(); it1 != it->second.end(); it1++) {
			k = 0;
			for (int i = 1; i <= n; i++) {
				if (scores[i][it->first].find(*it1) != scores[i][it->first].end()) {
					k = i;
					break;
				}
			}
			printf("%s %d %d %d\n", it1->c_str(), ranks[0][it->first], k, ranks[k][it->first]);
		}
	}
	return 0;
}

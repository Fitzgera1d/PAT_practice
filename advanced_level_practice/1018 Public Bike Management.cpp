#include <bits/stdc++.h>
using namespace std;
char output[100];

struct solution{
	string path;
	int send, get;
	friend bool operator < (solution a, solution b) {
		if (a.send == b.send) {
			return a.get < b.get;
		}
		return a.send < b.send;
	}
};

int main() {
    int capacity, n, problem, m;
	scanf("%d%d%d%d", &capacity, &n, &problem, &m); 
	int standard = capacity / 2;
	vector<int> stations(n+1);
	vector<int> distances(n+1, 100000000);
	vector<set<solution> > prevs(n+1);
	set<int> unvisited;
	map<int, map<int, int> > roads;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &stations[i]);
		unvisited.insert(i);
	}
	for (int i = 0; i < m; i++) {
		int _src, _tar, _time;
		scanf("%d%d%d", &_src, &_tar, &_time);
		roads[_src][_tar] = _time;
		roads[_tar][_src] = _time;
		if (_src * _tar == 0) {
			distances[_src==0?_tar:_src] = _time;
			sprintf(output, "0->%d", _src==0?_tar:_src);
			solution so;
			so.path = output;
			so.send = stations[_src==0?_tar:_src] > standard ? 0 : (standard - stations[_src==0?_tar:_src]);
			so.get = stations[_src==0?_tar:_src] > standard ? (stations[_src==0?_tar:_src] - standard) : 0;
			prevs[_src==0?_tar:_src].insert(so);
		}
	}
	int node = 0;
	while (node != problem) {
		int min_distance = 100000000;
		for (int i = 1; i<= n; i++) {
			if (unvisited.find(i) == unvisited.end()) {
				continue;
			}
			if (min_distance > distances[i]) {
				min_distance = distances[i];
				node = i;
			}
		}
		unvisited.erase(unvisited.find(node));
		for (int i = 1; i<= n; i++) {
			if (unvisited.find(i) == unvisited.end()) {
				continue;
			}
			if (roads[node].find(i) == roads[node].end()) {
				continue;
			}
			if (roads[node][i] + distances[node] <= distances[i]) {
				if (roads[node][i] + distances[node] < distances[i]) {
					prevs[i].clear();
				}
				for (auto it = prevs[node].begin(); it != prevs[node].end(); it++) {
					solution so = *it;
					sprintf(output, "->%d", i);
					so.path += string(output);
					if (so.get + stations[i] < standard) {
						so.send += standard - stations[i] - so.get;
						so.get = 0;
					} else {
						so.get += stations[i] - standard;
					}
				    prevs[i].insert(so);
				}
				distances[i] = roads[node][i] + distances[node];
			}
		}
	}
	solution result = *prevs[problem].begin();
	printf("%d %s %d\n", result.send, result.path.c_str(), result.get);
	return 0;
}

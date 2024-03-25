#include <bits/stdc++.h>
using namespace std;

map<int, vector<int> > highways;
vector<int> cities;

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++){
		cities.push_back(i);
	}
	for(int i = 0; i < m; i++){
		int p0, p1;
		scanf("%d%d", &p0, &p1);
		highways[p0].push_back(p1);
		highways[p1].push_back(p0);
	}
	for(int i = 0; i < k; i++){
		int lost;
		scanf("%d", &lost);
		vector<int> unvisited = cities;
		unvisited.erase(unvisited.begin() + lost - 1);
		vector<set<int> > groups;
		queue<int> visitQueue;
		while(!unvisited.empty()) {
			if(visitQueue.empty()) {
				visitQueue.push(unvisited[0]);
				unvisited.erase(unvisited.begin());
				groups.resize(groups.size()+1);
			}
			int city = visitQueue.front();
			visitQueue.pop();
			groups[groups.size()-1].insert(city);
			for(auto it = highways[city].begin(); it != highways[city].end(); it++) {
				auto _it = find(unvisited.begin(), unvisited.end(), *it);
				if(_it != unvisited.end()){
					visitQueue.push(*it);
					unvisited.erase(_it);
				}
			}
		}
		printf("%d\n", groups.size()-1);
	}
	return 0;
}

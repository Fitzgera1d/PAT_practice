#include <bits/stdc++.h>
#include <string.h>
#include <set>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
struct city{
	int dist;
	int teams;
	int no;
	set<int> prev;
	bool visited;
	city(){
		this->visited = false;
		this->dist = -1;
	}
	friend bool operator < (city a, city b) {
		return (!a.visited) && (a.dist >= 0) && (b.visited ||  a.dist < b.dist);
	}
};

map<int, int> dist[500];	// dist[source][dest] = dist

int main() {
	int city_num, road_num, c1, c2, i, next;
	scanf("%d%d%d%d", &city_num, &road_num, &c1, &c2);
	city cities[city_num], temp_city, const_city;
	const_city.visited = true;
	const_city.dist = 10000000;
	for(i = 0; i < city_num; i++){
		scanf("%d", &cities[i].teams);
		cities[i].no = i;
	}
	cities[c1].dist = 0;
	cities[c1].prev.insert(c1);
	int temp1, temp2;
	for(i = 0; i < road_num; i++){
		scanf("%d%d", &temp1, &temp2);
		dist[temp1][temp2] = 0;
		scanf("%d", &dist[temp1][temp2]);
		dist[temp2][temp1] = dist[temp1][temp2];
		if (temp2 == c1) { cities[temp1].dist = dist[temp1][temp2]; }
		if (temp1 == c1) { cities[temp2].dist = dist[temp1][temp2]; }
	}
	next = c1;
	while(next != c2){
		cities[next].visited = true;
		for(map<int, int>::iterator it = dist[next].begin(); it != dist[next].end(); it++){
			if(cities[it->first].dist != -1){
				if(cities[it->first].dist > cities[next].dist + it->second){
					cities[it->first].dist = cities[next].dist + it->second;
					cities[it->first].prev.clear();
					cities[it->first].prev.insert(next);
				} else if (cities[it->first].dist == cities[next].dist + it->second){
					cities[it->first].prev.insert(next);
				}
			} else {
				cities[it->first].dist = cities[next].dist + it->second;
				cities[it->first].prev.insert(next);
			}
		}
		temp_city = const_city;
		for(i = 0; i < city_num; i++){
			temp_city = cities[i] < temp_city? cities[i]: temp_city;
		}
		next = temp_city.no;
	}
	int result[1000][2], count = 1;
	result[0][0] = c2;
	result[0][1] = cities[c2].teams;
	bool term;
	while(true) {
		term = true;
		for(i = 0; i < count; i++) {
			if (result[i][0] != c1) {
				term = false;
				if (cities[result[i][0]].prev.size() > 1){
					for(set<int>::iterator sit = cities[result[i][0]].prev.begin(); sit != cities[result[i][0]].prev.end(); sit++){
						if (sit == cities[result[i][0]].prev.begin()) {
							continue;
						}
						result[count++][0] = *sit;
						result[count-1][1] = result[i][1] + cities[*sit].teams;
					}
				}
				result[i][0] = *cities[result[i][0]].prev.begin();
				result[i][1] += cities[result[i][0]].teams;
			}
		}
		if (term) {
			break;
		}
	}
	int _max = -1;
	for(i = 0; i < count; i++) {
		_max = max(_max, result[i][1]);
	}
	printf("%d %d\n", count, _max);
	return 0;
}


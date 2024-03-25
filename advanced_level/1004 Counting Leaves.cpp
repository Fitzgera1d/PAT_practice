#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
map<string, vector<string> > tree_nodes;
vector<queue<string> > buffer(2);

int main() {
	int n, m, i, j, k;
	char s[3], _s[3];
	string str, _str;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++){
		scanf("%s%d", s, &k);
		str = s;
		for (j = 0; j < k; j++){
			scanf("%s", _s);
			_str = _s;
			tree_nodes[str].push_back(_str);
		}
	}
	i = 0;
	j = 1;
	buffer[i].push("01");
	do{
		k = 0;
		while(!buffer[i].empty()){
			str = buffer[i].front();
			buffer[i].pop();
			if(tree_nodes.find(str) != tree_nodes.end()){
				for (m = 0; m < tree_nodes[str].size(); m++){
					buffer[j].push(tree_nodes[str][m]);
				}
			} else {
				k++;
			}
		}
		printf("%d", k);
		swap(i, j);
		if(!buffer[i].empty()) {
			printf(" ");
		}
	}while(!buffer[i].empty());
	printf("\n");
	return 0;
}

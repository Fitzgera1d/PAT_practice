#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, _id, _tmp;
	map<string, set<int> > libraries[6];
	scanf("%d", &n);
	char str[100];
	string _str;
	for (int i = 0; i < n; i++) {
		scanf("%d\n", &_id);
		fgets(str, 100, stdin); _str = str; _str.erase(_str.end()-1);
		libraries[1][_str].insert(_id);
		fgets(str, 100, stdin); _str = str; _str.erase(_str.end()-1);
		libraries[2][_str].insert(_id);
		do {
			scanf("%s", str);
			libraries[3][str].insert(_id);
		} while(getchar() != '\n');
		fgets(str, 100, stdin); _str = str; _str.erase(_str.end()-1);
		libraries[4][_str].insert(_id);
		fgets(str, 100, stdin); _str = str; _str.erase(_str.end()-1);
		libraries[5][_str].insert(_id);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d: ", &_tmp);
		fgets(str, 100, stdin); _str = str; _str.erase(_str.end()-1);
		printf("%d: %s\n", _tmp, _str.c_str());
		if (libraries[_tmp].find(_str) == libraries[_tmp].end()) {
			printf("Not Found\n");
		} else {
			for (auto it = libraries[_tmp][_str].begin(); it != libraries[_tmp][_str].end(); it++) {
				printf("%07d\n", *it);
			}
		}
	}
	return 0;
}

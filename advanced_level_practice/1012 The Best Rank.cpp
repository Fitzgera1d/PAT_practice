#include <bits/stdc++.h>
using namespace std;

struct student{
	int grades[4];
	int ranking[4];
};

int main() {
	int n, m;
	char _name[7];
	string name;
	vector<map<int, int, greater<int> > > grades(4), rankings(4);
	map<string, student> students;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", _name);
		name = _name;
		for(int j = 1; j < 4; j++){
			scanf("%d", &students[name].grades[j]);
			grades[j][students[name].grades[j]] += 1;
		}
		students[name].grades[0] = (students[name].grades[1]+students[name].grades[2]+students[name].grades[3])/3;
		grades[0][students[name].grades[0]] += 1;
	}
	for(int i = 0; i < 4; i++){
		int temp0 = 1, temp1 = 0;
		for(map<int, int>::iterator it = grades[i].begin(); it != grades[i].end(); it++){
			rankings[i][it->first] = temp0 + temp1;
			temp0 = rankings[i][it->first];
			temp1 = it->second;
		}
	}
	for(int i = 0; i < m; i++){
		scanf("%s", _name);
		name = _name;
		if(students.find(name) != students.end()){
			for(int j = 0; j < 4; j++){
				students[name].ranking[j] = rankings[j][students[name].grades[j]];
			}
			int _min = (int)(min_element(students[name].ranking, students[name].ranking+4)-students[name].ranking);
			char a[5] = "ACME";
			printf("%d %c\n", students[name].ranking[_min], a[_min]);
		} else {
			printf("N/A\n");
		}
	}
	return 0;
}

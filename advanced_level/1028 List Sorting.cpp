#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, index, grade;
	char str[100];
	map<string, set<vector<string> > > students;
	scanf("%d%d", &n, &index);
	for (int i = 0; i < n; i++) {
		vector<string> student;
		scanf("%s", str);
		student.push_back(str);
		scanf("%s", str);
		student.push_back(str);
		scanf("%d", &grade);
		sprintf(str, "%03d", grade);
		student.push_back(str);
		students[student[index-1]].insert(student);
	}
	for (auto it = students.begin(); it != students.end(); it++) {
		set<vector<string> > students_set = it->second;
		for (auto it1 = students_set.begin(); it1 != students_set.end(); it1++) {
			printf("%s %s ", (*it1)[0].c_str(), (*it1)[1].c_str());
			sscanf((*it1)[2].c_str(), "%d", &grade);
			printf("%d\n", grade);
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct book {
	int id;
	string title;
	string author;
	set<string> keywords;
	string publisher;
	int year;
};

int main() {
	int n, _tmp;
	scanf("%d", &n);
	char _str[100];
	for (int i = 0; i < n; i++) {
		book temp;
		scanf("%d", &_tmp);
		temp.id = _tmp;
		gets(_str);
		temp.title = _str;
		gets(_str);
		temp.author = _str;
		do {
			scanf("%s", _str);
			temp.keywords.insert(string(_str));
		} while(getchar() != '\n');
		gets(_str);
		temp.publisher = _str;
		scanf("%d", &_tmp);
		temp.year = _tmp;
	}
	return 0;
}

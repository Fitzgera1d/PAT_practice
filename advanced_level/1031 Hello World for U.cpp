#include <bits/stdc++.h>
using namespace std;

int main() {
	char input[100];
	string str;
	scanf("%s", input);
	str = input;
	int n = (str.size() + 2) / 3 - 1;
	int n1 = str.size() - 2 * n;
	for (int i = 0; i < n; i++) {
		printf("%c", str[i]);
		for (int j = 0; j < n1-2; j++) {
			printf(" ");
		}
		printf("%c\n", str[str.size()-i-1]);
	}
	printf("%s\n", str.substr(n, n1).c_str());
	return 0;
}

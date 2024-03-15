#include <bits/stdc++.h>
using namespace std;

string getChar(int n) {
	string _temp;
	if (n <= 9) {
		_temp = '0' + n;
	} else {
		_temp = 'A' + n - 10;
	}
	return _temp;
}

int main() {
	const int radix = 13;
	vector<int> colors(3);
	string output = "#";
	for (int i = 0; i < 3; i++) {
		scanf("%d", &colors[i]);
		output += getChar(colors[i] / radix) + getChar(colors[i] % radix);
	}
	printf("%s\n", output.c_str());
	return 0;
}

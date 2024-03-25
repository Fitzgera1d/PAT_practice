#include <bits/stdc++.h>
using namespace std;

int main() {
	char input[20];
	int max_iter, i;
	scanf("%s%d", input, &max_iter);
	string num = input;
	for (i = 0; i < max_iter; i++) {
		string _num = num;
		reverse(_num.begin(), _num.end());
		if (_num == num) {
			break;
		} else {
			int _sign = 0;
			for (int j = 0; j < num.size(); j++) {
				int _tmp = num[num.size()-1-j] - '0' + _num[num.size()-1-j] - '0' + _sign;
				_sign = _tmp / 10;
				num[num.size()-1-j] = _tmp % 10 + '0';
			}
			if (_sign == 1) {
				num.insert(num.begin(), '1');
			}
		}
	}
	printf("%s\n%d\n", num.c_str(), i);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> nums(10, 0), target;
	char _input[25];
	scanf("%s", _input);
	string input = _input;
	bool signal = 0;
	for (int i = 0; i < input.size(); i++) {
		int _tmp = (int)(input[i] - '0');
		nums[_tmp] += 1;
		if (_tmp >= 5) {
			if (i == 0) {
				signal = 1;
			} else {
				target[target.size()-1] += 1;
			}
		}
		target.push_back((_tmp * 2) % 10);
	}
	if (signal) {
		printf("No\n1");
	} else {
		for (int i = 0; i < target.size(); i++) {
			nums[target[i]] -= 1;
		}
		if (*max_element(nums.begin(), nums.end()) != 0) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
	for (int i = 0; i < target.size(); i++) {
		printf("%d", target[i]);
	}
	printf("\n");
	return 0;
}

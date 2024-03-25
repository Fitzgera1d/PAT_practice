#include <bits/stdc++.h>
using namespace std; 

int main() {
	int n, b;
	scanf("%d%d", &n, &b);
	vector<int> nums, _nums;
	while (n != 0) {
		nums.push_back(n % b);
		n /= b;
	}
	_nums = nums;
	reverse(nums.begin(), nums.end());
	if (_nums == nums) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	for(int i = 0; i < nums.size() - 1; i++){
		printf("%d ", nums[i]);
	}
	printf("%d\n", nums[nums.size()-1]);
	return 0;
}

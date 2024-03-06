#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int trans(char c){
	return ((int)c <= (int)'9') ? ((int)c - (int)'0') : ((int)c - (int)'a' + 10);
}

char retra(int n){
	if (n >= 36) return '{';
	return (n <= 9) ? (char)('0' + n) : (char)('a' + n - 10);
}

int main() {
	int tag;
	long long _radix, radix;
	char n1[15], n2[15];
	const long long _max = 1000000000LL;
	scanf("%s %s %d %lld", &n1, &n2, &tag, &_radix);
	string str1 = n1, str2 = n2;
	if(tag == 2){
		swap(str1, str2);
	}
	reverse(str1.begin(), str1.end());
	long long _value = 0LL;
	long long _base = 1LL;
	for(int i = 0; i < str1.length(); i++){
		_value += (long long)trans(str1[i]) * _base;
		_base *= (long long)_radix;
	}
//	int floor = trans(*max_element(str2.begin(), str2.end()));
	long long tmp = (long long)trans(str2[0]);
	long long floor = 2LL;
	if (str2.size() >= 1){
		floor = (long long)max(2.0, pow(_value/double(tmp+1), 1/double(str2.size())));
	}
	long long upper = (long long)max(floor + 2, _value + 2);
	long long result = -1LL;
	for(radix = (floor+upper) / 2; floor < upper; radix = (floor+upper) / 2){
		long long base = _value;
		for(int i = 0; i < str2.length() - 1; i++){
			base /= radix;
		}
		if (base > tmp){
			floor = max(radix, floor+1);
		} else if (base == tmp) {
			base = _value;
			reverse(str2.begin(), str2.end());
			string str3;
			for(int i = 0; i < str2.length(); i++){
				str3.push_back(retra(base % radix));
				base /= radix;
			}
			reverse(str2.begin(), str2.end());
			reverse(str3.begin(), str3.end());
			if (base > 0) {
				floor = max(radix, floor+1);
				continue;
			}
			if (str2 < str3) {
				floor = max(radix, floor+1);
			} else if (str2 > str3) {
				upper = min(radix, upper-1);
			} else {
				result = radix;
				upper = min(radix, upper-1);
			}
		} else {
			upper = min(radix, upper-1);
		}
	}
	if(result == -1LL){
		printf("Impossible\n");
	} else {
 	    printf("%lld\n", radix);
	}
	return 0;
}

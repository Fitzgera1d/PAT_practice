#include <bits/stdc++.h>
using namespace std; 

bool isPrime(int num) {
	if(num <= 1){
		return false;
	}
	bool is_prime = true;
	for(int i = 2; i <= sqrt(num) + 0.01; i++){
		if(num%i == 0){
			is_prime = false;
			break;
		}
	}
	return is_prime;
}

int main() {
	int n, d;
	while(scanf("%d", &n) != EOF){
		if(n < 0){
			break;
		}
		scanf("%d", &d);
		int num = n, _num = 0;
		string _n;
		while(n != 0) {
			_n.push_back('0' + (n % d));
			n /= d;
		}
		for(int i = 0; i < _n.size(); i++){
			_num += (int)(_n[i] - '0') * pow(d, _n.size() - i - 1);
		}
		if (isPrime(num) && isPrime(_num)){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}

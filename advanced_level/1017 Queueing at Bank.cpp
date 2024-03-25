#include <bits/stdc++.h>
using namespace std; 

struct custom{
	int arrive;
	int wait;
	int process;
	custom(int _a, int _p){
		this->wait = 0;
		this->process = _p * 60;
		this->arrive = _a;
	}
	friend bool operator > (custom a, custom b) {
		return a.arrive > b.arrive;
	}
};

int main() {
	int n, k, wait_time = 0;
	const int start_time = 8 * 60 * 60, end_time = 17 * 60 * 60;
	scanf("%d%d", &n, &k);
	priority_queue<custom, vector<custom>, greater<custom> > customs;
	priority_queue<int, vector<int>, greater<int> > windows(k, start_time);
	for (int i = 0; i < n; i++){
		int _h, _m, _s, _p;
		scanf("%d:%d:%d %d", &_h, &_m, &_s, &_p);
		int _t = ((_h * 60) + _m) * 60 + _s;
		if(_t <= end_time) {
			customs.push(custom(_t, _p));
		}
	}
	n = customs.size(); 
	while(!customs.empty()){
		int window_time = windows.top();
		custom custom = customs.top();
		windows.pop();
		customs.pop();
		int _start = max(window_time, custom.arrive);
		custom.wait += _start - custom.arrive;
		if (custom.process > 3600){
			custom.arrive = _start + 3600;
			custom.process -= 3600;
			customs.push(custom);
			windows.push(_start + 3600);
		} else {
			windows.push(_start + custom.process);
			wait_time += custom.wait;
		}
	}
	if(n == 0) {
		printf("0.0\n");
	} else {
		printf("%.1lf\n", wait_time/(60.0*n));
	}
	return 0;
}

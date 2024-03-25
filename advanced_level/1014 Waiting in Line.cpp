#include <bits/stdc++.h>
#include <queue>
using namespace std; 

struct custom{
	int window;
	int time;
	custom(int _w, int _t){
		this->window = _w;
		this->time = _t;
	}
	friend bool operator > (custom a, custom b){
		if (a.time == b.time){
			return a.window > b.window;
		}
		return a.time > b.time;
	}
};

int main() {
	int n, m, k, q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	vector<int> customs(k);
	vector<int> windows(n);
	priority_queue<custom, vector<custom>, greater<custom> > lines;
	for (int i = 0; i < k; i++){
		int _time, j;
		scanf("%d", &_time);
		if (i < m * n){
			j = i % n;
		} else {
			custom cus = lines.top();
			lines.pop();
			j = cus.window;
		}
		windows[j] += _time;
		if ((windows[j] - _time) < 540){
			customs[i] = windows[j];
		} else {
			customs[i] = 600;
		}
		lines.push(custom(j, windows[j]));
	}
	
	for (int i = 0; i < q; i++){
		int _custom;
		scanf("%d", &_custom);
		int t = customs[_custom - 1];
		if(t >= 600) {
			printf("Sorry\n");
		} else {
			int _h = 8 + t / 60;
			int _m = t % 60;
			printf("%02d:%02d\n", _h, _m);
		}
	}
	return 0;
}

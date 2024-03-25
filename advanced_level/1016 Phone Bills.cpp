#include <bits/stdc++.h>
using namespace std; 

vector<int> tolls(24);

struct record {
	int month;
	int time;
	bool is_online;
	record(int _mo, int _d, int _h, int _m, string _online){
		this->month = _mo;
		this->time = ((_d * 24) + _h) * 60 + _m;
		this->is_online = _online == "on-line";
	}
};

bool cmp(record a, record b) {
	if (a.month != b.month){
		return a.month < b.month;
	}
	return a.time < b.time;
}

double getCost(record begin, record end) {
	double cost = 0.0;
	int time = begin.time;
	if (begin.month == end.month) {
		int delta_time = (-time) % 60;
		if (delta_time == 0) { delta_time = 60; }
		while (time + delta_time < end.time) {
			cost += delta_time * tolls[(time/60)%24] / 100.0;
			time += delta_time;
			delta_time = (-time) % 60;
			if (delta_time == 0) { delta_time = 60; }
		}
		cost += (end.time-time) * tolls[(time/60)%24] / 100.0;
	}
	return cost;
}

int main() {
	int n, _mo = 0, _d = 0, _h = 0, _m = 0;
	map<string, vector<record> > records;
	char name[21] = "", type[10] = "off-line";
	for(int i = 0; i < 24; i++) {
		scanf("%d", &tolls[i]);
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d:%d %s", name, &_mo, &_d, &_h, &_m, type);
		records[string(name)].push_back(
		    record(_mo, _d, _h, _m, string(type))
		);
	}
	for(auto it = records.begin(); it != records.end(); it++){
		double total = 0;
		vector<record> _re = it->second;
		sort(_re.begin(), _re.end(), cmp);
		for (int i = 0; i < _re.size();){
			if (i == _re.size() - 1){
				_re.erase(_re.begin()+i);
				continue; 
			}
			if (_re[i].is_online && !_re[i+1].is_online) {
				i += 2;
			} else {
				_re.erase(_re.begin()+i);
			}
		}
		if(_re.size() == 0){
			continue;
		}
		printf("%s %02d\n", it->first.c_str(), it->second[0].month);
		for (int i = 0; i < _re.size(); i += 2){
			printf("%02d:%02d:%02d ", _re[i].time/(24*60), (_re[i].time/60)%24, _re[i].time%60);
			printf("%02d:%02d:%02d ", _re[i+1].time/(24*60), (_re[i+1].time/60)%24, _re[i+1].time%60);
			printf("%d ", _re[i+1].time - _re[i].time);
			double temp = getCost(_re[i], _re[i+1]);
			printf("$%.2lf\n", temp);
			total += temp;
		}
		printf("Total amount: $%.2lf\n", total);
	}
	return 0;
}

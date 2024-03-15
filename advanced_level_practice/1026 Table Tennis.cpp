#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int END =  21 * 3600, BEGIN = 8 * 3600;
struct table {
	int id, time, service;
	bool vip;
	table (int _id, bool _vip): id(_id), vip(_vip) {
		this->time = BEGIN;
		this->service = 0;
	}
	friend bool operator > (table a, table b) {
		return (a.time == b.time) ? (a.id > b.id) : (a.time > b.time);
	}
};

struct user {
	int arrive, serve, wait;
	user(int _a, int _s): arrive(_a), serve(_s) {
		this->wait = 0;
	}
	friend bool operator > (user a, user b) {
		return a.arrive > b.arrive;
	}
};

bool cmp(table a, table b) {
	return a.id < b.id;
}

int main() {
	int n, m, k, _h, _m, _s, _time, _vip, _t;
	scanf("%d", &n);
	priority_queue<table, vector<table>, greater<table> > tables;
	priority_queue<user, vector<user>, greater<user> > users, vip_users;
	set<int> vips;
	for (int i = 1; i <= n; i++) {
		scanf("%d:%d:%d %d %d", &_h, &_m, &_s, &_time, &_vip);
		user _user((_h * 60 + _m) * 60 + _s, min(_time * 60, 7200));
		if (_user.arrive >= END) {
			continue;
		}
		if (_vip == 1) {
			vip_users.push(_user);
		} else {
			users.push(_user);
		}
	}
	scanf("%d%d", &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &_m);
		vips.insert(_m);
	}
	for (int i = 1; i <= m; i++) {
		table _table(i, vips.find(i) != vips.end());
		tables.push(_table);
	}
	while (!users.empty() || !vip_users.empty()) {
		table _table = tables.top();
		user _user(0, 0);
		if (_table.time >= END) {
			break;
		}
		tables.pop();
		_time = min((users.empty()?END:users.top().arrive), (vip_users.empty()?END:vip_users.top().arrive));
		if (_table.time < _time) {
			_table.time = _time;
			tables.push(_table);
			continue;
		}
		_vip = 0;
		if (users.empty()) {
			_user = vip_users.top();
			vip_users.pop();
			_vip = 1;
		} else if (vip_users.empty()) {
			_user = users.top();
			users.pop();
		} else if (_table.vip) {
			if (vip_users.top().arrive <= _table.time) {
				_user = vip_users.top();
				vip_users.pop();
				_vip = 1;
			} else if (vip_users.top() > users.top()) {
				_user = users.top();
				users.pop();
			} else {
				_user = vip_users.top();
				vip_users.pop();
				_vip = 1;
			}
		} else {
		    if (vip_users.top() > users.top()) {
				_user = users.top();
				users.pop();
			} else {
				_user = vip_users.top();
				vip_users.pop();
				_vip = 1;
			}
		}
		if (_vip && !_table.vip) {
			vector<table> _tables;
			_tables.push_back(_table);
			while(!tables.empty()) {
				if (tables.top().time != _table.time) {
					_table = _tables[0];
					_tables.erase(_tables.begin());
					break;
				} else if (tables.top().vip) {
					_table = tables.top();
					tables.pop();
					break;
				}
				_table = tables.top();
				_tables.push_back(_table);
				tables.pop();
			}
			while(!_tables.empty()) {
				tables.push(_tables[0]);
				_tables.erase(_tables.begin());
			}
		}
		_table.service += 1;
		_user.wait = max(_user.arrive, _table.time) - _user.arrive;
		_table.time = _user.arrive + _user.wait + _user.serve;
		printf("%02d:%02d:%02d ", _user.arrive/3600, (_user.arrive/60)%60, _user.arrive%60);
		printf("%02d:%02d:%02d %d\n", (_user.arrive+_user.wait)/3600, ((_user.arrive+_user.wait)/60)%60, (_user.arrive+_user.wait)%60, ((_user.wait+30)/60));
		tables.push(_table);
	}
	vector<table> _tables;
	while (!tables.empty()) {
		_tables.push_back(tables.top());
		tables.pop();
	} 
	sort(_tables.begin(), _tables.end(), cmp);
	for (int i = 0; i < m - 1; i++) {
		printf("%d ", _tables[i].service);
	}
	printf("%d\n", _tables[m-1].service);
	return 0;
}

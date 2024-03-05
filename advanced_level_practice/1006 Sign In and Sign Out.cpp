#include <stdio.h> 
#include <queue>
#include <string>
using namespace std;

char name[20];
char iotime[20];
struct people{
	string name;
	string time;
	people(char _name[], char _time[]){
		this->name = _name;
		this->time = _time; 
	}
	friend bool operator > (people a, people b) {
		return a.time > b.time;
	}
	friend bool operator < (people a, people b) {
		return a.time < b.time;
	}
};

int main(){
	int m;
	priority_queue<people, vector<people>, greater<people> > inQue;
	priority_queue<people, vector<people>, less<people> > outQue;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%s%s", name, iotime);
		inQue.push(people(name, iotime));
		scanf("%s", iotime);
		outQue.push(people(name, iotime));
	}
	printf("%s %s\n", inQue.top().name.c_str(), outQue.top().name.c_str());	
	return 0;
}

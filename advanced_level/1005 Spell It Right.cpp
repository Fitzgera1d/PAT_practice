#include <map>
#include <string>
#include <iostream>
using namespace std;

char n[102];
map<char, string> characters;

int main() {
	characters['0'] = "zero";
	characters['1'] = "one";
	characters['2'] = "two";
	characters['3'] = "three";
	characters['4'] = "four";
	characters['5'] = "five";
	characters['6'] = "six";
	characters['7'] = "seven";
	characters['8'] = "eight";
	characters['9'] = "nine";
	scanf("%s", n);
	int sum = 0, temp = 0;
	string str = n;
	for(int i = 0; i < str.length(); i++){
		sscanf(str.substr(i, 1).c_str(), "%d", &temp);
		sum += temp;
	}
	sprintf(n, "%d", sum);
	str = n;
	for(int i = 0; i < str.length(); i++){
		printf("%s", characters[str[i]].c_str());
		if(i != str.length() - 1){
			printf(" ");
		}
	}
	printf("\n");
}

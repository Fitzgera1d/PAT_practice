#include <bits/stdc++.h>
using namespace std;

int main() {
	double input, output = 0.65;
	vector<char> infoMap = {'W', 'T', 'L'};
	vector<vector<double> > info(3, vector<double>(0));
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%lf", &input);
			info[i].push_back(input);
		}
	}
	for(int i = 0; i < 3; i++){
		auto maxCursor = max_element(info[i].begin(), info[i].end());
		output *= *maxCursor;
		printf("%c ", infoMap[maxCursor-info[i].begin()]);
	}
	output = (output - 1) * 2;
	printf("%.2lf\n", output);
	return 0;
}

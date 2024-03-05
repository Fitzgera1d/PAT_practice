#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	int k, i, j, left = 0, right = 0, max = -1, temp = 0;
	vector<int> vt;
	scanf("%d", &k);
	for(i = 0; i < k; i++){
		scanf("%d", &j);
		vt.push_back(j);
	}
	i = 0;
	for(j = 0; j < k; j++){
		
		temp += vt[j];
		if(temp > max){
			max = temp;
			left = i;
			right = j;
		} else if (temp < 0){
			temp = 0;
			i = j + 1;
		}
	}
	if(max < 0){
		left = 0;
		right = k-1;
		max = 0;
	}
	printf("%d %d %d\n", max, vt[left], vt[right]);
	return 0;
}

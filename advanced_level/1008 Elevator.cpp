#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, floor = 0, time = 0, next;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		time += 5;
		scanf("%d", &next);
		if (next != floor){
			time += (next > floor) ? (next - floor) * 6 : (next - floor) * -4;
			floor = next;
		}
	}
	printf("%d\n", time);
	return 0;
}

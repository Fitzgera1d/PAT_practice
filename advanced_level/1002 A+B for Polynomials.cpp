#include <bits/stdc++.h>
#include <map>
#include <math.h>
using namespace std;

int main() {
	int k, n, i;
	double a;
	map<int, double, greater<int> > mp;
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d%lf", &n, &a);
		mp[n] = a;
	}
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d%lf", &n, &a);
		if(mp.find(n) != mp.end()){
			mp[n] += a;
			if (mp[n] == 0) {
				mp.erase(n);
			}
		} else {
			mp[n] = a;
		}
	}
	if (mp.empty()) {
	   printf("0\n");
	   return 0;
	} 
	printf("%d", mp.size());
	for (map<int, double, greater<int> >::iterator it = mp.begin(); it != mp.end(); it++) {
		printf(" %d %.1lf", it->first, it->second);
	}
	printf("\n");
	
	return 0;
}

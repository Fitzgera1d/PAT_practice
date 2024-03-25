#include <bits/stdc++.h>
using namespace std;

int main(){
	map<int, double, greater<double> > x, y, z;
	map<int, double>::iterator it1, it2;
	int k, i, j;
	double input;
	scanf("%d", &k);
	for(i = 0; i < k; i++){
		scanf("%d%lf", &j, &input);
		x[j] = input;
	}
	scanf("%d", &k);
	for(i = 0; i < k; i++){
		scanf("%d%lf", &j, &input);
		y[j] = input;
	}
	for(it1 = x.begin(); it1 != x.end(); it1++) {
		for(it2 = y.begin(); it2 != y.end(); it2++) {
			z[it1->first+it2->first] += it1->second * it2->second;
			if(fabs(z[it1->first+it2->first]) < 0.1){
				z.erase(it1->first+it2->first);
			}
		}
	}
	printf("%d", z.size());
	for(it1 = z.begin(); it1 != z.end(); it1++){
		printf(" %d %.1lf", it1->first, it1->second);
	}
	printf("\n");
	return 0;
}

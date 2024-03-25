#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, temp, pn = 0, p = 0;
	scanf("%d", &n);
	vector<int> list(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	scanf("%d", &m);
	n = (n + m - 1) / 2;
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		while(pn < list.size()) {
			if (list[pn] > temp) {
				break;
			}
			if (p == n) {
				printf("%d\n", list[pn]);
				return 0;
			}
			p++;
			pn++;
		}
		if (p == n) {
			printf("%d\n", temp);
			return 0;
		}
		p++;
	}
	while(pn < list.size()) {
		if (p == n) {
			printf("%d\n", list[pn]);
			return 0;
		}
		p++;
		pn++;
	}
	return 0;
}

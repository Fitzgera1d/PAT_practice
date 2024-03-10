#include <bits/stdc++.h>
using namespace std;

vector<int> post_order, in_order;
struct node{
	int num;
	node* left;
	node* right;
	node(int _num){
		this->num = _num;
		this->left = NULL;
		this->right = NULL;
	}
};

node* getSub(vector<int>::iterator mid, vector<int>::iterator left, vector<int>::iterator right) {
	int _num = post_order[*mid];
	vector<int>::iterator _mid;
	node *temp = new node(_num);
	if (mid != left) {
		_mid = max_element(left, mid);
		temp->left = getSub(_mid, left, mid);
	}
	if (mid != right - 1) {
		_mid = max_element(mid + 1, right);
		temp->right = getSub(_mid, mid+1, right);
	}
	return temp;
}

void releaseSub(node* temp) {
	if (temp != NULL) {
		releaseSub(temp->left);
		releaseSub(temp->right);
		delete temp;
	}
}

int main() {
	int n, _num;
	scanf("%d", &n);
	post_order.resize(n);
	queue<node*> nq;
	for (int i = 0; i < n; i++) {
		scanf("%d", &post_order[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &_num);
		in_order.push_back(find(post_order.begin(), post_order.end(), _num) - post_order.begin());
	}
	node *tree = getSub(max_element(in_order.begin(), in_order.end()), in_order.begin(), in_order.end());
	nq.push(tree);
	while (!nq.empty()) {
		node *temp = nq.front();
		nq.pop();
		printf("%d", temp->num);
		if (temp->left != NULL) {
			nq.push(temp->left);
		}
		if (temp->right != NULL) {
			nq.push(temp->right);
		}
		if (!nq.empty()) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	releaseSub(tree);
	return 0;
}

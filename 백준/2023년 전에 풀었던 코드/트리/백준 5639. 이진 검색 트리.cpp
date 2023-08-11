#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* node, int data) {
	if(node==NULL) {
		node = new Node();
		node->data=data;
		node->left = node->right = NULL;
	} else if(data<=node->data) {
		node->left = insert(node->left, data);
	} else {
		node->right = insert(node->right, data);
	}
	
	return node;	
}

void postOrder(Node* node) {
	if(node->left!=NULL) {
		postOrder(node->left);
	}
	if(node->right!=NULL) {
		postOrder(node->right);
	}
	cout << node->data << "\n";
}
int main() {
	int num;
	Node* root=NULL;
	while(cin>>num) {
		if(num==EOF) break;
		root = insert(root, num);
	}
	postOrder(root);
	return 0;
}

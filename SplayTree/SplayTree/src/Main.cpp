#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include"../include/AVLTree.h"
#include"../include/SplayTree.h"

using namespace std;

int main() {
	AVLTree* avlTree = new AVLTree();

	vector<int> res1;

	avlTree->insert(1);
	avlTree->insert(3);
	avlTree->insert(5);
	avlTree->erase(1);
	avlTree->insert(-2);
	avlTree->erase(3);
	avlTree->insert(-10);

	res1 = avlTree->inorderTraversal();
	for (int num : res1) {
		cout << num << " ";
	}
	cout << endl;

	cin.get();
	return 0;
}
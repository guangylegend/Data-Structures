#ifndef AVLTREE_H
#define AVLTREE_H

#include <vector>
#include <algorithm>

class AVLTree {
private:

	struct node {
		node *left, *right;
		int height;
		int val;
		node(int value) : left(nullptr), right(nullptr), val(value), height(0) {}
	};

	node *root;
	int t_size;

	int height(node* x) {
		if (!x)return 0;
		else return x->height;
	}

	node* left_rotate(node* x) {
		node* y = x->right;
		x->right = y->left;
		y->left = x;
		
		x->height = std::max(height(x->left), height(x->right)) + 1;
		y->height = std::max(height(y->left), height(y->right)) + 1;
		return y;
	}

	node* right_rotate(node* x) {
		node* y = x->left;
		x->left = y->right;
		y->right = x;

		x->height = std::max(height(x->left), height(x->right)) + 1;
		y->height = std::max(height(y->left), height(y->right)) + 1;
		return y;
	}

	node* right_left_rotate(node* x) {
		x->right = right_rotate(x->right);
		return left_rotate(x);
	}

	node* left_right_rotate(node* x) {
		x->left = left_rotate(x->left);
		return right_rotate(x);
	}

	node* subtree_min(node* x) {
		while (x->left) {
			x = x->left;
		}
		return x;
	}

	node* subtree_max(node* x) {
		while (x->right) {
			x = x->right;
		}
		return x;
	}

	node* insert_utility(node* x, int key) {
		if (!x) {
			x = new node(key);
		}
		else if (x->val > key) {
			x->left = insert_utility(x->left, key);
			if (height(x->left) - height(x->right) == 2) {
				if (x->left->val > key) {
					x = right_rotate(x);
				}
				else if (x->left->val < key) {
					x = left_right_rotate(x);
				}
			}
		}
		else {
			x->right = insert_utility(x->right, key);
			if (height(x->right) - height(x->left) == 2) {
				if (x->right->val > key) {
					x = right_left_rotate(x);
				}
				else if(x->right->val < key){
					x = left_rotate(x);
				}
			}
		}
		x->height = std::max(height(x->left), height(x->right)) + 1;
		return x;
	}

	node* erase_utility(node* x, int key) {
		if (x) {
			if (x->val == key) {
				if (x->left && x->right) {
					if (height(x->left) > height(x->right)) {
						node* smax = subtree_max(x->left);
						x->val = smax->val;
						x->left = erase_utility(x->left, smax->val);
					}
					else {
						node* smin = subtree_min(x->right);
						x->val = smin->val;
						x->right = erase_utility(x->right, smin->val);
					}
				}
				else {
					node* tmp = x;
					if (x->left) {
						x = x->left;
						delete tmp;
						return x;
					}
					else if (x->right) {
						x = x->right;
						delete tmp;
						return x;
					}
					delete tmp;
					return nullptr;
				}
			}
			else if (x->val > key) {
				x->left = erase_utility(x->left, key);
				if (height(x->right) - height(x->left) == 2) {
					if (height(x->right->left) > height(x->right->right)) {
						x = right_left_rotate(x);
					}
					else {
						x = left_rotate(x);
					}
				}
			}
			else {
				x->right = erase_utility(x->right, key);
				if (height(x->left) - height(x->right) == 2) {
					if (height(x->left->right) > height(x->left->left)) {
						x = left_right_rotate(x);
					}
					else {
						x = right_rotate(x);
					}
				}
			}
			x->height = std::max(height(x->left), height(x->right)) + 1;
			return x;
		}
		return nullptr;
	}

	void inorderTraversal_utility(node* x, std::vector<int>& res) {
		if (!x)return;
		inorderTraversal_utility(x->left, res);
		res.push_back(x->val);
		inorderTraversal_utility(x->right, res);
	}

public:
	AVLTree() : root(nullptr), t_size(0) {}

	void insert(int key) {
		root = insert_utility(root, key);	
		t_size++;
	}

	node* find(int key) {
		node* r = root;
		while (r) {
			if (r->val > key)r = r->left;
			else if (r->val < key)r = r->right;
			else return r;
		}
		return nullptr;
	}

	void erase(int key) {
		root = erase_utility(root, key);
		t_size--;
	}

	int size() {
		return t_size;
	}

	std::vector<int> inorderTraversal() {
		std::vector<int> res;
		inorderTraversal_utility(root, res);
		return res;
	}
};

#endif
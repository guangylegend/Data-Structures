#ifndef SPLAYTREE_H
#define SPLAYTREE_H

class SplayTree {
private:
	
	struct node {
		node *left, *right;
		node *parent;
		int val;
		node(int value) : left(nullptr), right(nullptr), parent(nullptr), val(value) {}
	};

	node *root;
	int t_size;

	void left_rotate(node* x) {
		node* y = x->right;
		if (y) {
			x->right = y->left;
			if (y->left) {
				y->left->parent = x;
			}
			y->parent = x->parent;
		}
		if (!x->parent)root = y;
		else if (x == x->parent->left) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
		if (y) y->left = x;
		x->parent = y;
	}

	void right_rotate(node* x) {
		node* y = x->left;
		if (y) {
			x->left = y->right;
			if (y->right) {
				y->right->parent = x;
			}
			y->parent = x->parent;
		}
		if (!x->parent)root = y;
		else if (x == x->parent->left) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
		if (y) y->right = x;
		x->parent = y;
	}

	void splay(node* x) {
		while (x->parent) {
			if (!x->parent->parent) {
				if (x->parent->left == x) {
					right_rotate(x->parent);
				}
				else left_rotate(x->parent);
			}
			else if (x->parent->left == x && x->parent->parent->left == x->parent) {
				right_rotate(x->parent->parent);
				right_rotate(x->parent);
			}
			else if (x->parent->right == x && x->parent->parent->right == x->parent) {
				left_rotate(x->parent->parent);
				left_rotate(x->parent);
			}
			else if (x->parent->left == x && x->parent->parent->right == x->parent) {
				right_rotate(x->parent);
				left_rotate(x->parent);
			}
			else {
				left_rotate(x->parent);
				right_rotate(x->parent);
			}
		}
	}

	void replace(node* x, node* y) {
		if (!x->parent) {
			root = y;
		}
		else if (x == x->parent->left) {
			x->parent->left = y;
		}
		else if (x == x->parent->right) {
			x->parent->right = y;
		}
		if (y) {
			y->parent = x->parent;
		}
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
public:
	SplayTree() : root(nullptr), t_size(0) {}

	void insert(int key) {
		node* r = root;
		node* p = nullptr;
		while (r) {
			p = r;
			if (r->val > key)r = r->left;
			else r = r->right;
		}
		r = new node(key);
		r->parent = p;
		if (!p)root = r;
		else if (p->val > r->val)p->left = r;
		else p->right = r;
		splay(r);
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
		node* r = find(key);
		if (!r)return;

		splay(r);
		if (!r->left)replace(r, r->right);
		else if(!r->right)replace(r, r->left);
		else {
			node* smin = subtree_min(r->right);
			if (smin->parent != r) {
				replace(smin, smin->right);
				smin->right = r->right;
				smin->right->parent = smin;
			}
			replace(r, smin);
			smin->left = r->left;
			smin->left->parent = smin;
		}
		delete r;
		t_size--;
	}
	
};

#endif
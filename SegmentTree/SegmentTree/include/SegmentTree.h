#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include <vector>

using namespace std;
class SegmentTree {
private:
	struct node {
		node *left, *right;
		int lindex, rindex;
		int val;
		node(int value, int l, int r) : left(nullptr), right(nullptr), val(value), lindex(l), rindex(r) {}
	};

	node *root;
	int t_size;
	vector<int> array;

	node* buildTree(int l, int r) {
		node* n = new node(0, l, r);
		if (l == r)return n;
		n->left = buildTree(l, (r - l) / 2 + l);
		n->right = buildTree((r - l) / 2 + l + 1, r);
		return n;
	}

	void update_helper(node* n, int index, int diff) {
		if (!n)return;
		n->val += diff;
		if (index <= (n->rindex - n->lindex) / 2 + n->lindex)update_helper(n->left, index, diff);
		else update_helper(n->right, index, diff);
	}

	int sum_helper(node* n, int l, int r) {
		if (l == n->lindex && r == n->rindex)return n->val;
		int mid = (n->rindex - n->lindex) / 2 + n->lindex;
		if (l > mid)return sum_helper(n->right, l, r);
		else if(r <= mid)return sum_helper(n->left, l, r);
		else return sum_helper(n->left, l, mid) + sum_helper(n->right, mid + 1, r);
	}

public:
	SegmentTree(const vector<int>& arr) {
		t_size = arr.size();
		array.resize(t_size);
		fill(array.begin(), array.end(), 0);	
		root = buildTree(0,t_size-1);
		for (int i = 0; i < t_size; i++) {
			update(i, arr[i]);
		}
	}

	void update(int index, int val) {
		update_helper(root, index, val - array[index]);
		array[index] = val;
	}

	int sum(int lindex, int rindex) {
		return sum_helper(root, lindex, rindex);
	}
};

#endif
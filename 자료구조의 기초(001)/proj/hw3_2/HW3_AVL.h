#ifndef HW3_AVL_H
#define HW3_AVL_H

#include "HW3_BST.h"

class AVL : public BST {
public:
	AVL();
	void insert(const int&, const double&);
	void remove(const int&);
private:
	int BF(TreeNode*);
	void insert(TreeNode*&, const int&, const double&);
	void rotateSingle(TreeNode *&);
	void rotateDouble(TreeNode *&);
	void remove(TreeNode*&, const int&);
};

AVL::AVL() {
	// TODO : Implement a constructor of AVL
	BST();
}

void AVL::insert(const int& key, const double& data) {
	// TODO : Implement an insert function of AVL Tree using private insert function
	insert(root, key, data);
}

void AVL::remove(const int& key) {
	// TODO : Implement a remove function of AVL Tree using private remove function
	remove(root, key);
}

int AVL::BF(TreeNode* curr_node) {
	// TODO : Return the balance factor of curr_node
	// BF = The height of left child node of curr_node - The height of right child node of curr_node
	if (curr_node == nullptr) return 0;
	return getLevelFromLeaf(curr_node->left) - getLevelFromLeaf(curr_node->right);
}


void AVL::insert(TreeNode*& curr_node, const int& key, const double& data) {
	// TODO : Insert new node in AVL tree
	if (curr_node == nullptr) {
		// TODO : Create a new node
		curr_node = new TreeNode(key, data);
	}
	else if (key < curr_node->key) {
		// TODO : Insert the node in left sub-tree with rotation process
		insert(curr_node->left, key, data);
	}
	else if (key > curr_node->key) {
		// TODO : Insert the node in right sub-tree with rotation process
		insert(curr_node->right, key, data);
	}
	else if (key == curr_node->key) {
		// TODO : Update when a node which has same key exists
		curr_node->data = data;
	}
	if (BF(curr_node) == -2 && BF(curr_node->left) == -1)
		rotateSingle(curr_node);
	if (BF(curr_node) == -2 && BF(curr_node->left) == -1)
		rotateDouble(curr_node);
	return;
}

void AVL::rotateSingle(TreeNode*& curr_node) {
	// TODO : Implement a rotateSingle function
	if (BF(curr_node) < 0) {
		TreeNode* newCurr = curr_node->right;
		curr_node->right = newCurr->left;
		newCurr->left = curr_node;
		curr_node = newCurr;
	}
	else {
		TreeNode* newCurr = curr_node->left;
		curr_node->left = newCurr->right;
		newCurr->right = curr_node;
		curr_node = newCurr;
	}
}

void AVL::rotateDouble(TreeNode*& curr_node) {
	// TODO : Implement a rotateDouble function
	if (BF(curr_node) < 0) rotateSingle(curr_node->right);
	else rotateSingle(curr_node->left);
	rotateSingle(curr_node);
}

void AVL::remove(TreeNode*& curr_node, const int& key) {
	// TODO : Implement a remove function with propagated rotation process
}

#endif

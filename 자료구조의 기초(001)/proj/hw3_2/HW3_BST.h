#ifndef HW3_BST_H
#define HW3_BST_H

#include "HW2_Queue.h"
#include <iostream>
using namespace std;

class TreeNode {
public:
	// TODO : Write down all member variables and a constructor
	int key;
	double data;
	TreeNode *left, *right;
	TreeNode();
	TreeNode(int k, double d);
};

TreeNode::TreeNode() {
	TreeNode(0, 0);
}

TreeNode::TreeNode(int k, double d) {
	key = k;
	data = d;
	left = nullptr;
	right = nullptr;
}

class BST {
public:
	BST();
	bool isEmpty();
	int getHeight();
	void inorder();
	void preorder();
	void postorder();
	void levelorder();
	virtual void insert(const int&, const double&);
	virtual void remove(const int&);
	double find(const int&);
protected:
	TreeNode *root;
	int getLevelFromLeaf(TreeNode *);
	void inorder(TreeNode *);
	void preorder(TreeNode *);
	void postorder(TreeNode *);
	void levelorder(TreeNode *);
	TreeNode* find(TreeNode *&, const int&);
	virtual void insert(TreeNode *&, const int&, const double&);
	TreeNode*& rightMostChild(TreeNode *&);
	void remove(TreeNode *&, const int&);
	void doRemoval(TreeNode *&);
	void noChildRemove(TreeNode *&);
	void oneChildRemove(TreeNode *&);
	void twoChildRemove(TreeNode *&);
};

BST::BST() {
	// TODO : Implement a constructor of BST
	root = nullptr;
}

bool BST::isEmpty() {
	// TODO : Return whether BST is empty
	return root == nullptr;
}

int BST::getHeight() {
	// TODO : Return the height of BST using protected getLevelFromLeaf function (-1 when root is nullptr)
	return getLevelFromLeaf(root);
}

int BST::getLevelFromLeaf(TreeNode *curr_node) {
	// TODO : Return the level of curr_node from a leaf node (-1 when curr_node is NULL)
	if (curr_node == nullptr) return -1;
	int leftLevel  = getLevelFromLeaf(curr_node->left);
	int rightLevel = getLevelFromLeaf(curr_node->right);
	return (leftLevel > rightLevel ? leftLevel : rightLevel) + 1;
}

void BST::inorder() {
	// TODO : Implement an inorder function of BST using protected inorder function
	inorder(root);
	cout << endl;
}

void BST::inorder(TreeNode *curr_node) {
	// TODO : Print the nodes in order of the inorder traversal starting at curr_node
	if (curr_node != nullptr) {
		inorder(curr_node->left);
		cout << '<' << curr_node->key << ", " << curr_node->data << "> ";
		inorder(curr_node->right);
	}
}

void BST::preorder() {
	// TODO : Implement an preorder function of BST using protected preorder function
	preorder(root);
	cout << endl;
}

void BST::preorder(TreeNode *curr_node) {
	// TODO : Print the nodes in order of the preorder traversal, starting at curr_node
	if (curr_node != nullptr) {
		cout << '<' << curr_node->key << ", " << curr_node->data << "> ";
		preorder(curr_node->left);
		preorder(curr_node->right);
	}
}

void BST::postorder() {
	// TODO : Implement an postorder function of BST using protected postorder function
	postorder(root);
	cout << endl;
}

void BST::postorder(TreeNode *curr_node) {
	// TODO : Print the nodes in order of the postorder traversal, starting at curr_node
	if (curr_node != nullptr) {
		postorder(curr_node->left);
		postorder(curr_node->right);
		cout << '<' << curr_node->key << ", " << curr_node->data << "> ";
	}
}

void BST::levelorder() {
	// TODO : Implement an levelorder function of BST using protected levelorder function
	levelorder(root);
}

void BST::levelorder(TreeNode *curr_node) {
	// TODO : Print the nodes in order of the levelorder traversal, starting at curr_node
	// You can use given Queue class
	Queue<TreeNode> q(1);
	q.push(*curr_node);
	while (!q.isEmpty()) {
		cout << '<' << q.getFront().key << ", " << q.getFront().data << "> ";
		if(q.getFront().left != nullptr) q.push(*(q.getFront().left));
		if(q.getFront().right != nullptr) q.push(*(q.getFront().right));
		q.pop();
	}
}

void BST::insert(const int& key, const double& data) {
	// TODO : Implement an insert function of BST using protected insert function
	insert(root, key, data);
}

void BST::insert(TreeNode*& curr_node, const int& key, const double& data) {
	// TODO : Insert a node with key and data in BST with curr_node as root
	if (curr_node == nullptr) {
		curr_node = new TreeNode(key, data);
		return;
	}
	if (curr_node->key == key) curr_node->data = data;
	else (curr_node->key > key) ? insert(curr_node->left, key, data) : 
		insert(curr_node->right, key, data);
}

void BST::remove(const int& key) {
	// TODO : Implement an remove function of BST using protected remove function
	remove(root, key);
}

void BST::remove(TreeNode*& curr_node, const int& key) {
	// TODO : Remove a node with key in BST with curr_node as root
	if (curr_node != nullptr) {
		if (curr_node->key == key) doRemoval(curr_node);
		else (curr_node->key > key) ? remove(curr_node->left, key) : 
			remove(curr_node->right, key);
	}
}

double BST::find(const int& key) {
	// TODO : Implement an find function of BST using protected find function
	if (find(root, key) == nullptr) return -1;
	return find(root, key)->data;
}

TreeNode* BST::find(TreeNode*& curr_node, const int& key) {
	// TODO : find a node with key in BST with curr_node as root
	if (curr_node == nullptr) return nullptr;
	if (curr_node->key == key) return curr_node;
	return (curr_node->key > key) ? find(curr_node->left, key) : 
		find(curr_node->right, key);
}

void BST::doRemoval(TreeNode *& curr_node) {
	// TODO : Implement a doRemoval function of BST using protected noChildRemove, oneChildRemove, twoChildRemove functions
	if (curr_node->left == nullptr && curr_node->right == nullptr) noChildRemove(curr_node);
	else if (curr_node->left != nullptr && curr_node->right != nullptr) twoChildRemove(curr_node);
}

void BST::noChildRemove(TreeNode *& curr_node) {
	// TODO : Remove a node in case of no child
	delete curr_node;
	curr_node = nullptr;
}

void BST::oneChildRemove(TreeNode *& curr_node) {
	// TODO : Remove a node in case of one child
	TreeNode* newCurr;
	(curr_node->left != nullptr) ? (newCurr = curr_node->left) : (newCurr = curr_node->right);
	delete curr_node;
	curr_node = newCurr;
}

void BST::twoChildRemove(TreeNode *& curr_node) {
	// TODO : Remove a node in case of two children
	TreeNode* rightMost = rightMostChild(curr_node->left);
	curr_node->key = rightMost->key;
	curr_node->data = rightMost->data;
	delete rightMost;
}

TreeNode *& BST::rightMostChild(TreeNode *& curr_node) {
	// TODO : Return the right most child in BST with curr_node as root
	if (curr_node->right == nullptr) return curr_node;
	return rightMostChild(curr_node->right);
}

#endif

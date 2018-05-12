#ifndef HW3_BST_H
#define HW3_BST_H

#include "HW2_Queue.h"
#include <iostream>
using namespace std;

class TreeNode {
public:
	// TODO : Write down all member variables and a constructor
};

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
}

bool BST::isEmpty() {
	// TODO : Return whether BST is empty
}

int BST::getHeight() {
	// TODO : Return the height of BST using protected getLevelFromLeaf function (-1 when root is nullptr)
}

int BST::getLevelFromLeaf(TreeNode *curr_node) {
	// TODO : Return the level of curr_node from a leaf node (-1 when curr_node is NULL)
}

void BST::inorder() {
	// TODO : Implement an inorder function of BST using protected inorder function
}

void BST::inorder(TreeNode *curr_node) {
	// TODO : Print the nodes in order of the inorder traversal starting at curr_node
}

void BST::preorder() {
	// TODO : Implement an preorder function of BST using protected preorder function
}

void BST::preorder(TreeNode *curr_node) {
	// TODO : Print the nodes in order of the preorder traversal, starting at curr_node
}

void BST::postorder() {
	// TODO : Implement an postorder function of BST using protected postorder function
}

void BST::postorder(TreeNode *curr_node) {
	// TODO : Print the nodes in order of the postorder traversal, starting at curr_node
}

void BST::levelorder() {
	// TODO : Implement an levelorder function of BST using protected levelorder function
}

void BST::levelorder(TreeNode *curr_node) {
	// TODO : Print the nodes in order of the levelorder traversal, starting at curr_node
	// You can use given Queue class
}

void BST::insert(const int& key, const double& data) {
	// TODO : Implement an insert function of BST using protected insert function
}

void BST::insert(TreeNode*& curr_node, const int& key, const double& data) {
	// TODO : Insert a node with key and data in BST with curr_node as root
}

void BST::remove(const int& key) {
	// TODO : Implement an remove function of BST using protected remove function
}

void BST::remove(TreeNode*& curr_node, const int& key) {
	// TODO : Remove a node with key in BST with curr_node as root
}

double BST::find(const int& key) {
	// TODO : Implement an find function of BST using protected find function
}

TreeNode* BST::find(TreeNode*& curr_node, const int& key) {
	// TODO : find a node with key in BST with curr_node as root
}

void BST::doRemoval(TreeNode *& curr_node) {
	// TODO : Implement a doRemoval function of BST using protected noChildRemove, oneChildRemove, twoChildRemove functions
}

void BST::noChildRemove(TreeNode *& curr_node) {
	// TODO : Remove a node in case of no child
}

void BST::oneChildRemove(TreeNode *& curr_node) {
	// TODO : Remove a node in case of one child
}

void BST::twoChildRemove(TreeNode *& curr_node) {
	// TODO : Remove a node in case of two children
}

TreeNode *& BST::rightMostChild(TreeNode *& curr_node) {
	// TODO : Return the right most child in BST with curr_node as root
}

#endif

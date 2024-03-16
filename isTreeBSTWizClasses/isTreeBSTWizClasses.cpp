// Check if a tree is BST
// rules all left node < parent && right nodes
// all right nodes > parent && left node 
// all nodes must be unique 

#include<iostream>
class Node {
public:
	int data{};
	Node* left{};
	Node* right{};

	Node();
};

Node::Node() {
	this->data = 0;
	this->left = nullptr;
	this->right = nullptr;
}

class Tree {
public:
	Node* insertNode(int);
	int minValue(Node*) const;
	int maxValue(Node*) const;
	void printTree(Node*) const;
	bool isTreeBST(Node*) const;

};

Node* Tree::insertNode(int value) {
	Node* newNode = new Node();

	newNode->data = value;
	newNode->left = nullptr;
	newNode->right = nullptr;

	return newNode;
}

int Tree::maxValue(Node* node) const {
	if (node == nullptr)
		return INT32_MIN;

	int value = node->data;
	int left = maxValue(node->left);
	int right = maxValue(node->right);

	return std::max(value, std::max(left, right));
}

int Tree::minValue(Node* node) const {
	if (node == nullptr)
		return INT32_MAX;

	int value = node->data;
	int left = minValue(node->left);
	int right = minValue(node->right);

	return std::min(value, std::min(left, right));
}

bool Tree::isTreeBST(Node* node) const {
	if (node == nullptr)
		return true;

	if (node->left != nullptr && maxValue(node->left) > node->data)
		return false;

	if (node->right != nullptr && minValue(node->right) < node->data)
		return false;

	if (!isTreeBST(node->left) || !isTreeBST(node->right))
		return false;

	return true;
}

void Tree::printTree(Node* node) const {
	if (node == nullptr)
		return;

	printTree(node->left);
	std::cout << node->data << " ";
	printTree(node->right);
}


int main() {
	Tree myTree{};
	Node* root = myTree.insertNode(8);
	root->left = myTree.insertNode(5);
	root->right = myTree.insertNode(10);
	root->left->left = myTree.insertNode(2);
	root->left->right = myTree.insertNode(6);

	myTree.printTree(root);
	std::cout << "\nis my Tree a BST: " << myTree.isTreeBST(root) << std::endl;

	return 0;
}

































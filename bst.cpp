#include "bst.hpp"
#include <iostream>

Node * const Bst::getRoot() const
{
	return root;
}

Node * const Bst::getLeft(const Node * root) const
{
	return root->left;
}

Node * const Bst::getRight(const Node * root) const
{
	return root->right;
}

void Bst::insert(int value)
{
	Node * node = new Node(value);
	if (root == nullptr)
		root = node;
	else
		insertAt(root, node);
}

Node *  Bst::remove(int value)
{
	return remove(root, value);
}

Node * Bst::remove(Node * root, int value)
{
	if (root == nullptr)
		return root;

	if (value < root->value)
		root->left = remove(root->left, value);
	else if (value > root->value)
		root->right = remove(root->right, value);
	else
	{
		if (root->left == nullptr)
		{
			Node * newRoot = root->right;
			delete root;
			return newRoot;
		}
		if (root->right == nullptr)
		{
			Node * newRoot = root->left;
			delete root;
			return newRoot;
		}

		Node * successor = inOrderSuccessor(root->right);
		root->value = successor->value;
		root->right = remove(root->right, successor->value);
	}
	return root;
}

Node * Bst::inOrderSuccessor(Node * root)
{
	if (root->left == nullptr)
		return root;
	return inOrderSuccessor(root->left);
}

Node * Bst::find(int value)
{
	return find(root, value);
}

Node * Bst::find(Node * root, int value)
{
	if (root == nullptr)
		return root;
	if (root->value == value)
		return root;
	if (root->value < value)
		return find(root->right, value);
	return find(root->left, value);
}

std::string Bst::printInOrder()
{
	return inOrder(root);
}

std::string Bst::inOrder(Node * root)
{
	if (root == nullptr)
		return "";
	return inOrder(root->left) + " " + std::to_string(root->value) + " " + inOrder(root->right);
}

void Bst::insertAt(Node * root, Node * child)
{
	if (root->value >= child->value)
	{
		if (root->left == nullptr)
			root->left = child;
		else
			insertAt(root->left, child);
	}
	else
	{
		if (root->right == nullptr)
			root->right = child;
		else
			insertAt(root->right, child);
	}
}

int main()
{
	Bst bst;
	bst.insert(30);
	bst.insert(26);
	bst.insert(10);
	bst.insert(56);
	bst.insert(11);
	bst.insert(4);
	bst.insert(20);
	// const Node * n = bst.getRoot();
	// const Node * left = bst.getLeft(n);
	// const Node * right = bst.getRight(n);

	std::cout << bst.printInOrder() << std::endl;

	Node * found = bst.find(10);
	if (found)
		std::cout << found->value << std::endl;
	else
		std::cout << "null node" << std::endl;

	bst.remove(30);
	std::cout << bst.printInOrder() << std::endl;
	//std::cout << n->value << " " << left->value  << " " << right->value << std::endl;
	//std::cout << left->left->value << std::endl;
	return 0;
}
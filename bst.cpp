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

void Bst::insert(int n)
{
	Node * node = new Node(n);
	if (root == nullptr)
		root = node;
	else
		insertAt(root, node);
}

Node *  Bst::remove(int i)
{
	return remove(root, i);
}

Node * Bst::remove(Node * root, int i)
{
	if (root == nullptr)
		return root;

	if (i < root->value)
		root->left = remove(root->left, i);
	else if (i > root->value)
		root->right = remove(root->right, i);
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

Node * Bst::inOrderSuccessor(Node * node)
{
	if (node->left == nullptr)
		return node;
	return inOrderSuccessor(node->left);
}

Node * Bst::find(int i)
{
	return find(root, i);
}

Node * Bst::find(Node * n, int i)
{
	if (n == nullptr)
		return nullptr;
	if (n->value == i)
		return n;
	if (n->value < i)
		return find(n->right, i);
	return find(n->left, i);
}

std::string Bst::printInOrder()
{
	return inOrder(root);
}

std::string Bst::inOrder(Node * node)
{
	if (node == nullptr)
		return "";
	return inOrder(node->left) + " " + std::to_string(node->value) + " " + inOrder(node->right);
}

void Bst::insertAt(Node * parent, Node * n)
{
	if (parent->value >= n->value)
	{
		if (parent->left == nullptr)
			parent->left = n;
		else
			insertAt(parent->left, n);
	}
	else
	{
		if (parent->right == nullptr)
			parent->right = n;
		else
			insertAt(parent->right, n);
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
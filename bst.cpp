#include "bst.hpp"
#include <iostream>

template <typename T>
typename Bst<T>::Node * const Bst<T>::getRoot() const
{
	return root;
}

template <typename T>
typename Bst<T>::Node * const Bst<T>::getLeft(const Bst<T>::Node * root) const
{
	return root->left;
}

template <typename T>
typename Bst<T>::Node * const Bst<T>::getRight(const Bst<T>::Node * root) const
{
	return root->right;
}

template <typename T>
void Bst<T>::insert(T value)
{
	Bst<T>::Node * node = new Node(value);
	if (root == nullptr)
		root = node;
	else
		insertAt(root, node);
}

template <typename T>
typename Bst<T>::Node * Bst<T>::remove(T value)
{
	return remove(root, value);
}

template <typename T>
typename Bst<T>::Node * Bst<T>::remove(Bst<T>::Node * root, T value)
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

template <typename T>
typename Bst<T>::Node * Bst<T>::inOrderSuccessor(Bst<T>::Node * root)
{
	if (root->left == nullptr)
		return root;
	return inOrderSuccessor(root->left);
}

template <typename T>
typename Bst<T>::Node * Bst<T>::find(T value)
{
	return find(root, value);
}

template <typename T>
typename Bst<T>::Node * Bst<T>::find(Bst<T>::Node * root, T value)
{
	if (root == nullptr)
		return root;
	if (root->value == value)
		return root;
	if (root->value < value)
		return find(root->right, value);
	return find(root->left, value);
}

template <typename T>
std::string Bst<T>::printInOrder()
{
	return inOrder(root);
}

template <typename T>
std::string Bst<T>::inOrder(Bst<T>::Node * root)
{
	if (root == nullptr)
		return "";
	return inOrder(root->left) + " " + std::to_string(root->value) + " " + inOrder(root->right);
}

template <typename T>
void Bst<T>::insertAt(Bst<T>::Node * root, Bst<T>::Node * child)
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
	Bst<int> bst;
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

	Bst<int>::Node * found = bst.find(10);
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
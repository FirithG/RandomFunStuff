#include <string>

struct Node
{
	explicit Node(int n)
	{
		value = n;
	}

	int value;
	Node * left = nullptr;
	Node * right = nullptr;
};

class Bst
{

public:

	void insert(int value);
	std::string printInOrder();
	Node * find(int value);
	Node * remove(int value);

	Node * const getRoot() const;
	Node * const getLeft(const Node * const root) const;
	Node * const getRight(const Node * const root) const;
	Node * inOrderSuccessor(Node * root);

private:
	void insertAt(Node * root, Node * child);
	std::string inOrder(Node * root);
	Node * find(Node * root, int value);
	Node * remove(Node * root, int value);

	Node * root = nullptr;

};
	
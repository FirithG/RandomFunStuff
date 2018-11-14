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

	void insert(int n);
	std::string printInOrder();
	Node * find(int i);
	Node * remove(int i);

	Node * const getRoot() const;
	Node * const getLeft(const Node * const parent) const;
	Node * const getRight(const Node * const parent) const;
	Node * inOrderSuccessor(Node * n);

private:
	void insertAt(Node * parent, Node * n);
	std::string inOrder(Node * node);
	Node * find(Node * n, int i);
	Node * remove(Node * n, int i);

	Node * root = nullptr;

};
	
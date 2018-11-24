#include <string>

template <typename T>
class Bst
{
public:
	struct Node
	{
		explicit Node(T n)
		{
			value = n;
		}

		T value;
		Node * left = nullptr;
		Node * right = nullptr;
	};

	void insert(T value);
	std::string printInOrder();
	Node * find(T value);
	Node * remove(T value);

	Node * const getRoot() const;
	Node * const getLeft(const Node * const root) const;
	Node * const getRight(const Node * const root) const;
	Node * inOrderSuccessor(Node * root);

private:
	void insertAt(Node * root, Node * child);
	std::string inOrder(Node * root);
	Node * find(Node * root, T value);
	Node * remove(Node * root, T value);

	Node * root = nullptr;

};
	
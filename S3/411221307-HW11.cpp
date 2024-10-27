#include <bits/stdc++.h>

using namespace std;

template<class T>
class BinarySearchTree {
private:
	struct Node {
		T data;
		Node *left, *right;
	};
	void inorder(Node *cur) {
		if(!cur)
		return;
		inorder(cur->left);
		cout << cur->data << " ";
		inorder(cur->right);
	}
	Node *root;
public:
	BinarySearchTree() : root(nullptr) {}
	void insertElement(T d) {
		Node *newNode = new Node();
		newNode->data = d;
		newNode->left = newNode->right = nullptr;
		if (root == nullptr) {
			root = newNode;
			return;
		}
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node *current = q.front();
			q.pop();
			if (current->left == nullptr) {
				current->left = newNode;
				return;
			} else {
				q.push(current->left);
			}
			if (current->right == nullptr) {
				current->right = newNode;
				return;
			} else {
				q.push(current->right);
			}
		}
	}
	void print() {
		inorder(root);
		cout << endl;
	}
	bool search(T d) {
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node *current = q.front();
			q.pop();
			if (current->left != nullptr) 
				q.push(current->left);
			if (current->right != nullptr) 
				q.push(current->right);
			if (current->data == d)
				return true;
		}
		return false;
	}
	int height() {
		return heightHelper(root);
	}
	int heightHelper(Node *cur) {
		if(!cur)
			return 0;
		return 1 + max(heightHelper(cur->left), heightHelper(cur->right));
	}
};

int main() {
	int data;
	string command;
	BinarySearchTree<int> *bst = new BinarySearchTree<int>();
	while(true) {
		cin >> command;
		if(command == "insert") {
			cin >> data;
			bst->insertElement(data);
		}
		else if(command == "search") {
			cin >> data;
			if(bst->search(data))
				cout << "true" << endl;
			else
				cout << "false" << endl;
		}
		else if(command == "height") {
			cout << bst->height() << endl;
		}
		else if(command == "print") {
			bst->print();
		}
		else if(command == "exit") {
			break;
		}
	}
}

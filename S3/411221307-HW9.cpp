#include <bits/stdc++.h>

using namespace std;

template<class T>
class BinaryTreeInArray {
private:
	T *array;
	int height;
	int numOfElement;
	void resize(int size) { // but the size isn't used in the function bruh
		T *temp = new T[numOfElement];
		int j;
		for(j = 0;j < numOfElement;j ++)
		temp[j] = array[j];
		delete array;
		array = new T[static_cast<int>(pow(2, height + 1)) - 1];
		for(j = 0;j < numOfElement;j ++)
		array[j] = temp[j];
		height ++;
		delete temp;
	}
public:
	BinaryTreeInArray() : array(nullptr), height(0), numOfElement(0) {}
	void addElementAsCompleteTree(T data) {
		int cap = pow(2, height) - 1;
		if(numOfElement + 1 > cap)
		resize((cap + 1) * 2 - 1);
		array[numOfElement] = data;
		numOfElement ++;
	}
	void displayInorder() {
		inorder(array, 0, numOfElement);	
	}
	void inorder(int *arr, int index, int size) {
		if (index >= size) {
			return;
		}
		inorder(arr, 2 * index + 1, size); // left
		cout << arr[index] << " ";
		inorder(arr, 2 * index + 2, size); // right
	}
	void displayPreorder() {
		preorder(array, 0, numOfElement);
	}
	void preorder(int *arr, int index, int size) {
		if (index >= size) {
			return;
		}
		cout << arr[index] << " ";
		preorder(arr, 2 * index + 1, size); // left
		preorder(arr, 2 * index + 2, size); // right
	}
	void displayPostorder() {
		postorder(array, 0, numOfElement);
	}
	void postorder(int *arr, int index, int size) {
		if (index >= size) {
			return;
		}
		postorder(arr, 2 * index + 1, size); // left
		postorder(arr, 2 * index + 2, size); // right
		cout << arr[index] << " ";
	}
};

template<class T>
class BinaryTreeInLinkedList {
private:
	class TreeNode {
	private:
	public:
		TreeNode(T d) : data(d), left(nullptr), right(nullptr) {}
		TreeNode *left, *right;
		T data;
	};
	TreeNode *root;
	int numOfElement;
public:
	BinaryTreeInLinkedList() : root(nullptr), numOfElement(0) {}
	void addElementAsCompleteTree(T data) {
		TreeNode *newNode = new TreeNode(data);
		if (root == nullptr) {
			root = newNode;
			numOfElement++;
			return;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode *current = q.front();
			q.pop();
			if (current->left == nullptr) {
				current->left = newNode;
				numOfElement++;
				return;
			} else {
				q.push(current->left);
			}
			if (current->right == nullptr) {
				current->right = newNode;
				numOfElement++;
				return;
			} else {
				q.push(current->right);
			}
		}
	}
	void displayInorder() {
		inorder(root);
	}
	void inorder(TreeNode *node) {
		if (node == nullptr) {
			return;
		}
		inorder(node->left); // left
		cout << node->data << " ";
		inorder(node->right); // right
	}
	void displayPreorder() {
		preorder(root);
	}
	void preorder(TreeNode *node) {
		if (node == nullptr) {
			return;
		}
		cout << node->data << " ";
		preorder(node->left); // left
		preorder(node->right); // right
	}
	void displayPostorder() {
		postorder(root);
	}
	void postorder(TreeNode *node) {
		if (node == nullptr) {
			return;
		}
		postorder(node->left); // left
		postorder(node->right); // right
		cout << node->data << " ";
	}
};

int main()
{
	BinaryTreeInArray<int> *b = new BinaryTreeInArray<int>;
	BinaryTreeInLinkedList<int> *tree = new BinaryTreeInLinkedList<int>;
	int j, n;
	cin >> n;
	for(j = 0;j < n;j ++) {
		b->addElementAsCompleteTree(j);
		tree->addElementAsCompleteTree(j);
	}
	b->displayInorder();
	cout << endl;
	tree->displayInorder();
	cout << endl;
	b->displayPreorder();
	cout << endl;
	tree->displayPreorder();
	cout << endl;
	b->displayPostorder();
	cout << endl;
	tree->displayPostorder();
	cout << endl;
	return 0;
}

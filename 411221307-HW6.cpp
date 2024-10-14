#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 100

using namespace std;

class Node
{
public:
	Node()
	{
		next = NULL;
		pre = NULL;
	}
	Node(int n)
	{
		data = n;
		next = NULL;
		pre = NULL;
	}
	int getData() { return data; }
	Node *getNext() { return next; }
	Node *getPre() { return pre; }
	void setData(int d) { data = d; }
	void setNext(Node *n) { next = n; }
	void setPre(Node *p) { pre = p; }
private:
	int data;
	Node *next, *pre; 
};

class List
{
public:
	List() { list = NULL; }
	List(int n) { generate(n); }
	
	void generate(int n)
	{
		int j;
		list = NULL;
		for(j = 0;j < n;j ++)
			generate();
	}
	
	void generate()
	{
		Node *buf = new Node(rand());
		buf->setNext(list);
		if(list != NULL)
			list->setPre(buf);
		list = buf;
	}

	void swap(Node *a, Node *b) {
		Node *tmppre, *tmpnext;
		if (a -> getNext() == b) {
			if (a -> getPre() != NULL) a -> getPre() -> setNext(b);
			if (b -> getNext() != NULL) b -> getNext() -> setPre(a);
			a -> setNext(b -> getNext());
			b -> setPre(a -> getPre());
			a -> setPre(b);
			b -> setNext(a);
		} else if (b -> getNext() == a) {
			if (b -> getPre() != NULL) b -> getPre() -> setNext(a);
			if (a -> getNext() != NULL) a -> getNext() -> setPre(b);
			b -> setNext(a -> getNext());
			a -> setPre(b -> getPre());
			b -> setPre(a);
			a -> setNext(b);
		} else {
			if (a -> getPre() != NULL) a -> getPre() -> setNext(b);
			if (a -> getNext() != NULL) a -> getNext() -> setPre(b);
			if (b -> getPre() != NULL) b -> getPre() -> setNext(a);
			if (b -> getNext() != NULL) b -> getNext() -> setPre(a);
			tmppre = a -> getPre();
			a -> setPre(b -> getPre());
			b -> setPre(tmppre);
			tmpnext = a -> getNext();
			a -> setNext(b -> getNext());
			b -> setNext(tmpnext);
		}
	}
	
	void bubbleSort()
	{
		Node *end = list;
		while (end -> getNext() != NULL) {
			end = end -> getNext();
		}
		Node *i, *j = end;
		bool swapped = 0;
		while (j -> getPre() != NULL) {
			swapped = 0;
			i = list;
			while (i != j) {
				if (i -> getNext() -> getData() < i -> getData()) {
					Node *tmp = i -> getNext();
					if(tmp == j) j = i;
					swap(i, tmp);
					i = tmp;
					swapped = 1;
				}
				i = i -> getNext();
			}
			j = j -> getPre();
			if (!swapped) break;
			while (j -> getPre()!= NULL) {
				j = j -> getPre();
			}
			list = j;
		}
	}
	
	void selectionSort()
	{
		Node *i = list, *j, *minimum;
		while (i -> getNext() != NULL) {
			j = i -> getNext();
			minimum = i;
			while (j != NULL) {
				if (j -> getData() < minimum -> getData()) {
					minimum = j;
				}
				j = j -> getNext();
			}
			if (minimum != i) {
				swap(i, minimum);
				i = minimum;
			}
			i = i -> getNext();
		}
		while (i -> getPre() != NULL) {
			i = i -> getPre();
		}
		list = i;
	}
	
	void insertionSort()
	{
		Node *i = list -> getNext();
		while (i != NULL) {
			Node *j = i;
			while (j -> getPre() != NULL && j -> getPre() -> getData() > j -> getData()) {
				swap(j -> getPre(), j);
			}
			i = i -> getNext();
		}
		while (list -> getPre() != NULL) {
			list = list -> getPre();
		}
	} 
	
	void print()
	{
		Node *cur = list;
		while(cur != NULL)
		{
			cout<<cur->getData()<<" ";
			cur = cur->getNext();
		}
		cout<<endl;
	}
private:
	Node *list;
};

int main()
{
	srand(time(NULL));
	List *l = new List(10);
	l->print();
	l->bubbleSort();
	l->print();
	
	l = new List(10);
	l->print();
	l->insertionSort();
	l->print();
	
	l = new List(10);
	l->print();
	l->selectionSort();
	l->print();
}

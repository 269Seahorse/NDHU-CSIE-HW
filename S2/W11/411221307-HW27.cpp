#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
    public :
        class Node
        {
            public :
                Node() : next(nullptr), data(0) {}
                Node(int d) : next(nullptr), data(d) {}
                Node(Node *n) : next(n), data(0) {}
                Node(Node *n, int d) : next(n), data(d) {}
                int data ;
                Node *next ;
        } ;
        LinkedList(): head(NULL) {}
        ~LinkedList() {
            while(head != NULL){
                Node *nextDel = head;
                head = head -> next;
                delete nextDel;
            }
        }
        bool addFromHead(int d) {
            Node *newNode = new Node(d);
            if(newNode == NULL) return false;
            newNode -> next = head;
            head = newNode;
            return true;
        }
        bool addFromTail(int d) {
            Node *newNode = new Node(d);
            if(newNode == NULL) return false;
            if(head == NULL) {
                head = newNode;
                return true;
            }
            Node *ptr;
            for(ptr = head; ptr -> next != NULL; ptr = ptr -> next) continue;
            ptr -> next = newNode;
            return true;
        }
        bool removeFromHead() {
            if(head == NULL) return false;
            Node *ptr = head -> next;
            delete head;
            head = ptr;
            return true;
        }
        bool removeFromTail() {
            if(head == NULL) return false;
            if(head -> next == NULL) {
                delete head;
                head = NULL;
                return true;
            }
            Node *ptr;
            for(ptr = head; ptr -> next != NULL && ptr -> next -> next != NULL; ptr = ptr -> next) continue;
            delete ptr -> next;
            ptr -> next = NULL;
            return true;
        }
        friend ostream &operator<<(ostream &o, LinkedList *l) {
            o << "{";
            Node *ptr;
            for(ptr = l -> head; ptr != NULL; ptr = ptr -> next) {
                o << ptr -> data;
                if(ptr -> next != NULL) o << ", ";
            }
            o << "}\n";
            return o;
        }
        size_t getSize() const {
            size_t n = 0;
            Node *ptr;
            for(ptr = head; ptr != NULL; ptr = ptr -> next) n++;
            return n;
        }
    protected :
        Node *head ;
} ;
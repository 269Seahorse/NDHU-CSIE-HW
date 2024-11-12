#include <bits/stdc++.h>

using namespace std;

class ExpressionTree {
private:
    struct Node {
        std::string value;
        Node* left;
        Node* right;

        Node(const std::string& val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

	int priority(char c) {
		if (c == '+' || c == '-') return 1;
		if (c == '*' || c == '/' || c == '%') return 2;
		return 0;
	}

	string intopost(string inf) {
		stack<char> s;
		string post;
		for (int i = 0; i < inf.size(); i++) {
			if (inf[i] == ' ') continue;
			if (isdigit(inf[i])) {
				post += inf[i];
				while (isdigit(inf[i + 1])) {
					post += inf[i + 1];
					i++;
				}
				post += ' ';
			}
			else if (inf[i] == '(') s.push(inf[i]);
			else if (inf[i] == ')') {
				while (s.top() != '(') {
					post += s.top();
					post += ' ';
					s.pop();
				}
				s.pop();
			}
			else {
				if(inf[i] == '-' && isdigit(inf[i + 1])) {
					post += '-';
					continue;
				}
				while (!s.empty() && priority(s.top()) >= priority(inf[i])) {
					post += s.top();
					post += ' ';
					s.pop();
				}
				s.push(inf[i]);
			}
		}
		while (!s.empty()) {
			post += s.top();
			post += ' ';
			s.pop();
		}
		return post;
	}

	Node* buildTree(const string& postfix) {
        stack<Node*> st;
        istringstream iss(postfix);
        string token;
        while (iss >> token) {
            if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
                st.push(new Node(token));
            } else {
                Node* node = new Node(token);
                node->right = st.top(); 
				st.pop();
                node->left = st.top(); 
				st.pop();
                st.push(node);
            }
        }
        return st.top();
    }

public:
    //Constructor of class ExpressionTree take a string as an infix expression and build the expression tree base on that.
    //there are five different operation you have to consider, +(addition), -(subtraction), *(multiplication), /(division) and %(modulus).
    //you also need to consider -(negative) sign.
    //all operands are integer
    ExpressionTree(const std::string &expression) {
		string output = intopost(expression);
		// cout << output;
		root = buildTree(output);
    }

    ~ExpressionTree() { deleteTree(root); }

    void deleteTree(Node* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    //print all element in infix order.
    void printInFixOrder() {
        printInFixOrder(root);
		cout << endl;
    }

    void printInFixOrder(Node* node) {
        if (node == nullptr) return;
        if (node->left || node->right) cout << "(";
        printInFixOrder(node->left);
        cout << node->value << " ";
        printInFixOrder(node->right);
        if (node->left || node->right) cout << ")";
    }

    //print all element in prefix order.
    void printPreFixOrder() {
        printPreFixOrder(root);
		cout << endl;
    }

    void printPreFixOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        printPreFixOrder(node->left);
        printPreFixOrder(node->right);
    }

    //print all element in postfix order.
    void printPostFixOrder() {
        printPostFixOrder(root);
		cout << endl;
    }

    void printPostFixOrder(Node* node) {
        if (node == nullptr) return;
        printPostFixOrder(node->left);
        printPostFixOrder(node->right);
        cout << node->value << " ";
    }

    //evaluate the expression, this function return an int sience % can only work with integer in C
    int eval() {
        return evaluate(root);
    }

    int evaluate(Node* node) {
        if (isdigit(node->value[0]) || (node->value[0] == '-' && node->value.size() > 1)) {
            return stoi(node->value);
        }
        int leftVal = evaluate(node->left);
        int rightVal = evaluate(node->right);
        if (node->value == "+") return leftVal + rightVal;
        if (node->value == "-") return leftVal - rightVal;
        if (node->value == "*") return leftVal * rightVal;
        if (node->value == "/") return leftVal / rightVal;
        if (node->value == "%") return leftVal % rightVal;
        return 0;
    }
};

int main() {
    std::string infix = "( -12 + 3 ) * 4 % 5";
    //std::cin >> infix;
	getline(cin, infix);
    ExpressionTree exprTree(infix);

    std::cout << "Inorder: ";
    exprTree.printInFixOrder();
    std::cout << "Preorder: ";
    exprTree.printPreFixOrder();
    std::cout << "Postorder: ";
    exprTree.printPostFixOrder();
    std::cout << "Evaluated result: " << exprTree.eval() << std::endl;

    return 0;
}

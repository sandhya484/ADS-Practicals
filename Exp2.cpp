#include<iostream>
#include<stack>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

// check operator
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

// build tree from prefix
Node* buildTree(string exp) {
    stack<Node*> s;

    for(int i = exp.length()-1; i >= 0; i--) {
        Node* temp = new Node{exp[i], NULL, NULL};

        if(isOperator(exp[i])) {
            temp->left = s.top(); s.pop();
            temp->right = s.top(); s.pop();
        }
        s.push(temp);
    }
    return s.top();
}

// inorder display
void inorder(Node* root) {
    if(root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// non-recursive postorder
void postorder(Node* root) {
    if(!root) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while(!s1.empty()) {
        Node* temp = s1.top(); s1.pop();
        s2.push(temp);

        if(temp->left) s1.push(temp->left);
        if(temp->right) s1.push(temp->right);
    }

    while(!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    string exp;
    Node* root = NULL;
    int ch;

    do {
        cout << "\n1.Read 2.Build 3.Inorder 4.Postorder 5.Exit\n";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter prefix: ";
                cin >> exp;
                break;

            case 2:
                root = buildTree(exp);
                break;

            case 3:
                inorder(root);
                break;

            case 4:
                postorder(root);
                break;
        }
    } while(ch != 5);

    return 0;
}

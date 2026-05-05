#include<iostream>
using namespace std;

struct Node {
    string key, meaning;
    Node *left, *right;
    int height;
};

// height
int getH(Node* n) {
    if(n==NULL) return 0;
    return n->height;
}

// balance factor
int getBF(Node* n) {
    return getH(n->left) - getH(n->right);
}

// create node
Node* newNode(string k, string m) {
    Node* t = new Node;
    t->key = k;
    t->meaning = m;
    t->left = t->right = NULL;
    t->height = 1;
    return t;
}

// right rotate (LL)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;

    y->height = 1 + max(getH(y->left), getH(y->right));
    x->height = 1 + max(getH(x->left), getH(x->right));

    return x;
}

// left rotate (RR)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = 1 + max(getH(x->left), getH(x->right));
    y->height = 1 + max(getH(y->left), getH(y->right));

    return y;
}

// insert + balance
Node* insert(Node* root, string k, string m) {
    if(root==NULL) return newNode(k,m);

    if(k < root->key)
        root->left = insert(root->left,k,m);
    else if(k > root->key)
        root->right = insert(root->right,k,m);
    else
        return root;

    root->height = 1 + max(getH(root->left), getH(root->right));

    int bf = getBF(root);

    // LL
    if(bf > 1 && k < root->left->key)
        return rightRotate(root);

    // RR
    if(bf < -1 && k > root->right->key)
        return leftRotate(root);

    // LR
    if(bf > 1 && k > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if(bf < -1 && k < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// display sorted
void inorder(Node* root) {
    if(root) {
        inorder(root->left);
        cout << root->key << ":" << root->meaning << endl;
        inorder(root->right);
    }
}

// search
void search(Node* root, string key) {
    int count=0;
    while(root) {
        count++;
        if(key == root->key) {
            cout << "Found in " << count << " comparisons\n";
            return;
        }
        else if(key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    cout << "Not found\n";
}

int main() {
    Node* root = NULL;
    int ch;
    string k,m;

    do {
        cout << "\n1.Add 2.Display 3.Search 4.Exit\n";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter key & meaning: ";
                cin >> k >> m;
                root = insert(root,k,m);
                break;

            case 2:
                inorder(root);
                break;

            case 3:
                cout << "Enter key: ";
                cin >> k;
                search(root,k);
                break;
        }
    } while(ch != 4);

    return 0;
}

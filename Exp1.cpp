#include<iostream>
using namespace std;

struct Node {
    string word, meaning;
    Node *left, *right;
};

class BST {
    Node* root;

public:
    BST() { root = NULL; }

    // 1. ADD NODE
    Node* add(Node* root, string w, string m) {
        if (root == NULL) {
            Node* temp = new Node{w, m, NULL, NULL};
            return temp;
        }
        if (w < root->word)
            root->left = add(root->left, w, m);
        else if (w > root->word)
            root->right = add(root->right, w, m);
        else
            cout << "Duplicate word!\n";

        return root;
    }

    // 2. DISPLAY (ASCENDING)
    void display(Node* root) {
        if (root) {
            display(root->left);
            cout << root->word << " : " << root->meaning << endl;
            display(root->right);
        }
    }

    // 3. SEARCH
    void search(Node* root, string key) {
        int count = 0;
        while (root) {
            count++;
            if (key == root->word) {
                cout << "Found in " << count << " comparisons\n";
                return;
            }
            else if (key < root->word)
                root = root->left;
            else
                root = root->right;
        }
        cout << "Not found\n";
    }

    // 4. UPDATE
    void update(Node* root, string key) {
        while (root) {
            if (key == root->word) {
                cout << "Enter new meaning: ";
                cin >> root->meaning;
                return;
            }
            else if (key < root->word)
                root = root->left;
            else
                root = root->right;
        }
        cout << "Word not found\n";
    }

    // Find minimum (used in delete)
    Node* minValue(Node* root) {
        while (root->left)
            root = root->left;
        return root;
    }

    // 5. DELETE
    Node* deleteNode(Node* root, string key) {
        if (root == NULL) return root;

        if (key < root->word)
            root->left = deleteNode(root->left, key);
        else if (key > root->word)
            root->right = deleteNode(root->right, key);
        else {
            // node found
            if (root->left == NULL)
                return root->right;
            else if (root->right == NULL)
                return root->left;

            Node* temp = minValue(root->right);
            root->word = temp->word;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->word);
        }
        return root;
    }

    Node* getRoot() { return root; }
    void setRoot(Node* r) { root = r; }
};

int main() {
    BST b;
    int ch;
    string w, m;

    do {
        cout << "\n1.Add 2.Display 3.Delete 4.Update 5.Search 6.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter word & meaning: ";
                cin >> w >> m;
                b.setRoot(b.add(b.getRoot(), w, m));
                break;

            case 2:
                b.display(b.getRoot());
                break;

            case 3:
                cout << "Enter word: ";
                cin >> w;
                b.setRoot(b.deleteNode(b.getRoot(), w));
                break;

            case 4:
                cout << "Enter word: ";
                cin >> w;
                b.update(b.getRoot(), w);
                break;

            case 5:
                cout << "Enter word: ";
                cin >> w;
                b.search(b.getRoot(), w);
                break;
        }
    } while (ch != 6);

    return 0;
}

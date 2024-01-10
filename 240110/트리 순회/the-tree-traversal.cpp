#include <iostream>
#include <vector>
#define MAX 26

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
public:
    BST() : root(nullptr) {}

    void addNode(char rootVal, char leftVal, char rightVal) {
        if (root == nullptr) {
            root = new Node(rootVal);
        }

        Node* rootNode = findNode(root, rootVal);
        if (leftVal != '.') rootNode -> left = new Node(leftVal);
        if (rightVal != '.') rootNode -> right = new Node(rightVal);
    }

    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder (Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data;
            inorder(node->right);
        }
    }

    void postorder (Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data;
        }
    }

    Node* findNode(Node* node, char val) {
        if (node == nullptr) return nullptr;

        if (node->data == val) return node;

        Node* leftNode = findNode(node->left, val);
        if (leftNode != nullptr) return leftNode;

        return findNode(node->right, val);
    }

    void printBST() {
        preorder(root);
        cout << "\n";
        inorder(root);
        cout << "\n";
        postorder(root);
    }
};



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    BST tree;

    for (int i=0; i<n; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree.addNode(root, left, right);
    }

    tree.printBST();

    return 0;
}
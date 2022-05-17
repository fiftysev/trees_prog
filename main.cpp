#include <iostream>

typedef struct Node {
    int key;
    Node *left;
    Node *right;

    explicit Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
} Node;

class BST {
public:
    explicit BST() {
        root = nullptr;
    }

    bool isEmpty(Node* n) {
        return n == nullptr;
    }

    void insert(int value) {
        if (root != nullptr) insert(value, root);
        else root = new Node(value);
    }

    void deleteItem(int value) {
        if (!search(value, root)) {
            std::cout << "Invalid operation: item doesn't exist" << std::endl;
            return;
        }
        root = deleteNode(value, root);
    }

    Node* search(int value) {
        return search(value, root);
    }

    void preorder() {
        preorder(root);
    }

    void inorder() {
        inorder(root);
    }

    void postorder() {
        postorder(root);
    }
private:
    Node *root;

    void insert(int value, Node *node) {
        if (value < node->key) {
            if (node->left != nullptr) insert(value, node->left);
            else node->left = new Node(value);
            return;
        } else if (value > node->key) {
            if (node->right != nullptr) insert(value, node->right);
            else node->right = new Node(value);
        }
    }

    Node* deleteNode(int value, Node *node) {
        if (node == nullptr) return node;

        if (value < node->key) {
            node->left = deleteNode(value, node->left);
        }
        else if (value > node->key) {
            node->right = deleteNode(value, node->right);
        }

        else if (node->right != nullptr && node->left != nullptr) {
            node->key = min(node->right)->key;
            node->right = deleteNode(node->key, node->right);
        }

        else {
            if (node->left != nullptr) {
                node = node->left;
            }
            else if (node->right != nullptr) {
                node = node->right;
            }
            else node = nullptr;
        }
        return node;
    }

    Node* min(Node *n) {
        if (n->left == nullptr) return n;
        return min(n->left);
    }

    Node* max(Node *n) {
        if (n->right == nullptr) return n;
        return max(n->right);
    }

    Node* search(int value, Node *node) {
        if (isEmpty(node)) return nullptr;
        if (value == node->key) return node;
        return value < node->key ? search(value, node->left) : search(value, node->right) ;
    }

    void preorder(Node *_root) {
        if (_root) {
            std::cout << _root->key << " ";
            preorder(_root->left);
            preorder(_root->right);
        }
    }

    void inorder(Node *_root) {
        if (_root) {
            preorder(_root->left);
            std::cout << _root->key << " ";
            preorder(_root->right);
        }
    }

    void postorder(Node *_root) {
        if (_root) {
            preorder(_root->left);
            preorder(_root->right);
            std::cout << _root->key << " ";
        }
    }
};

int main() {
    BST tree = BST();
    for (int i = 0; i < 10; i++) {
        tree.insert(i);
    }
    return 0;
}

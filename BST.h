#include <iostream>
#include <string>

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

    bool isTreeEmpty() {
        return root == nullptr;
    }

    void insert(int value) {
       root = insert(value, root);
    }

    bool deleteItem(int value) {
        if (!search(value, root)) return false;
        root = deleteNode(value, root);
        return true;
    }

    Node* search(int value) {
        return search(value, root);
    }

    Node* next(int value) {
        Node* current = root;
        Node* successor = nullptr;
        while (current != nullptr) {
            if (value < current->key) {
                successor = current;
                current = current->left;
            }
            else current = current->right;
        }
        return successor;
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

    Node* insert(int value, Node *node) {
        if (node == nullptr) return new Node(value);
        else if (value < node->key) node->left = insert(value, node->left);
        else if (value > node-> key) node->right = insert(value, node->right);
        return node;
    }

    Node* deleteNode(int value, Node *node) {
        if (node == nullptr) return node;

        if (value < node->key) node->left = deleteNode(value, node->left);

        else if (value > node->key) node->right = deleteNode(value, node->right);

        else if (node->right != nullptr && node->left != nullptr) {
            node->key = min(node->right)->key;
            node->right = deleteNode(node->key, node->right);
        }
        else {
            if (node->left != nullptr) node = node->left;

            else if (node->right != nullptr) node = node->right;

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

    // Прямой
    void preorder(Node *_root) {
        if (_root) {
            std::cout << _root->key << " ";
            preorder(_root->left);
            preorder(_root->right);
        }
    }

    // Симметричный
    void inorder(Node *_root) {
        if (_root) {
            inorder(_root->left);
            std::cout << _root->key << " ";
            inorder(_root->right);
        }
    }

    // Обратный
    void postorder(Node *_root) {
        if (_root) {
            postorder(_root->left);
            postorder(_root->right);
            std::cout << _root->key << " ";
        }
    }
};

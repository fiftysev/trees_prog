#include <iostream>
#include <sstream>
#include <map>
#include "BST.h"


using namespace std;

void print_menu() {
    cout << "-------------------------" << endl;
    cout << "1. Add element(s)" << endl;
    cout << "2. Delete element" << endl;
    cout << "3. Find element" << endl;
    cout << "4. Inorder traversal" << endl;
    cout << "5. Preorder traversal" << endl;
    cout << "6. Postorder traversal" << endl;
    cout << "-------------------------" << endl;
}

int main() {
    BST tree = BST();
    int buf;
    string buffer;
    print_menu();
    stringstream ss;
    short cmd;
    while (cin >> cmd) {
        switch (cmd) {
            case 1:
                getline(cin, buffer);
                getline(cin, buffer);
                ss << buffer;
                while (ss >> buf) {
                    tree.insert(buf);
                }
                cout << "Success" << endl;
                print_menu();
                break;
            case 2:
                cin >> buf;
                if (!tree.deleteItem(buf)) cout << "Exception: Element is not found" << endl;
                else cout << "Success" << endl;
                print_menu();
                break;
            case 3:
                cin >> buf;
                if (tree.isTreeEmpty()) cout << "Exception: Tree is empty" << endl;
                else if (!tree.search(buf)) cout << "Element is not found" << endl;
                else cout << "Element is found" << endl;
                break;
            case 4:
                if (tree.isTreeEmpty()) cout << "Exception: Tree is empty" << endl;
                else {
                    cout << "Inorder traversal: ";
                    tree.inorder();
                    cout << endl;
                }
                print_menu();
                break;
            case 5:
                if (tree.isTreeEmpty()) cout << "Exception: Tree is empty" << endl;
                else {
                    cout << "Preorder traversal: ";
                    tree.preorder();
                    cout << endl;
                }
                print_menu();
                break;
            case 6:
                if (tree.isTreeEmpty()) cout << "Exception: Tree is empty" << endl;
                else {
                    cout << "Postorder traversal: ";
                    tree.postorder();
                    cout << endl;
                }
                print_menu();
                break;
            default:
                cout << "Invalid operation" << endl;
                print_menu();
                break;
        }
    }
    return 0;
}

#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include "BST.h"


using namespace std;

void print_menu() {
    cout << "-------------------------" << endl;
    cout << "1. Add element" << endl;
    cout << "2. Delete element" << endl;
    cout << "3. Clear tree data" << endl;
    cout << "4. Find element" << endl;
    cout << "5. Inorder traversal" << endl;
    cout << "6. Preorder traversal" << endl;
    cout << "7. Postorder traversal" << endl;
    cout << "8. Get next element" << endl;
    cout << "9. Pretty print" << endl;
    cout << "-------------------------" << endl;
}

vector<int> get_input(const string& s) {
    vector<int> v;
    int buf;
    istringstream ss;
    ss.clear();
    ss.str(s);
    while (ss >> buf || !ss.eof()) {
        if (ss.fail()) {
            ss.clear();
            ss.ignore(1);
            continue;
        }
        v.push_back(buf);
    }
    return v;
}

int main() {
    BST tree = BST();
    int buf;
    string buffer;
    print_menu();
    stringstream ss;
    vector<int> data;
    short cmd;
    do {
        cin >> cmd;
        switch (cmd) {
            case 1:
                cout << "Enter key(s) (to break input enter any letter):" << endl;
                getline(cin >> ws, buffer);
                data = get_input(buffer);
                if (data.empty()) cout << "Invalid input or process terminated" << endl;
                for (auto v : data) {
                    cout << v << " ";
                    tree.search(v) ? cout << "Already exists" << endl : cout << "Inserted" << endl;
                    tree.insert(v);
                }
                print_menu();
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> buf;
                if (!cin.good()) {
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Value must be int" << endl;
                    print_menu();
                    break;
                }
                else if (tree.isTreeEmpty()) cout << "Exception: Tree is empty" << endl;
                else if (!tree.deleteItem(buf)) cout << "Exception: Element is not found" << endl;
                else cout << "Success" << endl;
                print_menu();
                break;
            case 3:
                cout << "Tree data cleared" << endl;
                tree = BST();
                print_menu();
                break;
            case 4:
                cout << "Enter key: ";
                cin >> buf;
                if (!cin.good()) {
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Key must be int" << endl;
                    print_menu();
                    break;
                }
                if (tree.isTreeEmpty()) {
                    cout << "Exception: Tree is empty" << endl;
                }
                else if (!tree.search(buf)) cout << "Element is not found" << endl;
                else cout << "Element is found" << endl;
                print_menu();
                break;
            case 5:
                if (tree.isTreeEmpty()) cout << "Exception: Tree is empty" << endl;
                else {
                    cout << "Inorder traversal: ";
                    tree.inorder();
                    cout << endl;
                }
                print_menu();
                break;
            case 6:
                if (tree.isTreeEmpty()) cout << "Exception: Tree is empty" << endl;
                else {
                    cout << "Preorder traversal: ";
                    tree.preorder();
                    cout << endl;
                }
                print_menu();
                break;
            case 7:
                if (tree.isTreeEmpty()) cout << "Exception: Tree is empty" << endl;
                else {
                    cout << "Postorder traversal: ";
                    tree.postorder();
                    cout << endl;
                }
                print_menu();
                break;
            case 8:
                cout << "Enter key: ";
                cin >> buf;
                Node* res;
                if (tree.isTreeEmpty()) cout << "Exception: Tree is empty" << endl;
                else if (!cin.good()) {
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Element must be int" << endl;
                    print_menu();
                    break;
                }
                else {
                    res = tree.next(buf);
                    res == nullptr ? cout << "Next element is undefined" << endl : cout << res->key << endl;
                    print_menu();
                }
                break;
            case 9:
                if (tree.isTreeEmpty()) cout << "Exception: Tree is empty" << endl;
                else tree.pretty_print();
                print_menu();
                break;
            case 0:
                break;
            default:
                cout << "Invalid operation" << endl;
                print_menu();
                break;
        }
    } while (cmd != 0);
    return 0;
}

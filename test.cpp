#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (!root) return createNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

Node* find(Node* root, int value) {
    if (!root || root->value == value)
        return root;
    if (value < root->value)
        return find(root->left, value);
    return find(root->right, value);
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (!root) return nullptr;

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    return root;
}

int main() {
    Node* root = nullptr;
    cout << "Binary Search Tree Create\n1. File input\n2. Data input\nChoice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        string filename;
        cout << "File name: ";
        cin >> filename;
        ifstream infile(filename);
        if (!infile) {
            cerr << "Failed to open file.\n";
            return 1;
        }
        int number;
        while (infile >> number) {
            root = insert(root, number);
        }
        infile.close();
    } else {
        cout << "Enter numbers (end with -1): ";
        int number;
        while (cin >> number && number != -1) {
            root = insert(root, number);
        }
    }

while (true) {
    cout << "\nBinary Search Tree Menu\n1. Insert\n2. Delete\n3. Find\n4. Sort\n5. Exit\nChoice: ";
    int op;
    cin >> op;
    if (op == 1) {
        int val;
        cout << "Enter value to insert: ";
        cin >> val;
        root = insert(root, val);
        cout << "Tree after insert (Inorder): ";
        inorder(root);
        cout << endl;
    } else if (op == 2) {
        int val;
        cout << "Enter value to delete: ";
        cin >> val;
        root = deleteNode(root, val);
        cout << "Tree after delete (Inorder): ";
        inorder(root);
        cout << endl;
    } else if (op == 3) {
        int val;
        cout << "Enter value to find: ";
        cin >> val;
        Node* result = find(root, val);
        if (result) {
            cout << "Value " << val << " found in the tree.\n";
        } else {
            cout << "Value " << val << " not found in the tree.\n";
        }
    } else if (op == 4) {
        cout << "Sorted values: ";
        inorder(root);
        cout << endl;
    } else if (op == 5) {
        cout << "Exiting.\n";
        break;
    } else {
        cout << "Invalid choice.\n";
    }
}
    return 0;
}

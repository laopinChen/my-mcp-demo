#include<iostream>
#include <fstream>
using namespace std;

int main() {
    cout << "Binary Search Tree Create\n1. File input\n2. Data input\nChoice: ";
    int choice;
    string filename;
    cin >> choice;
    cout<<"file name:";
    cin >> filename;
    ifstream infile(filename);
    if (!infile) {
        cerr << "Failed to open file: " << filename << endl;
        return 1;
    }
    int number;
    cout << "Numbers in file:\n";
    while (infile >> number) {
        cout << number << " ";
    }
    cout << "\nDone reading.\n";
    infile.close();
    cout <<"Binary Search Tree\n1.insert\n2.delete\n3.find\n4.sort"<<endl;
    int choice1;
    cout<<"choice:";
    cin>>choice1;
    int data;
    cout<<"data:";
    cin>>data;
    typedef struct node{
    int value;
    struct node *left;
    struct node *right;
    } node;
    Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
    }
    Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
    }
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

    return 0;
}

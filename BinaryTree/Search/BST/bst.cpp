#include <bits/stdc++.h>
using namespace std;
#define LL long long int

typedef struct node{
    int data;
    node* left;
    node* right;
}node;

node* new_node(int value){
    node* temp = (node *) malloc(sizeof(node));
    temp->data = value;
    temp->left = temp->right = NULL;

    return temp;
}

node* insert(node* root, int value){
    if (root == NULL)
        return new_node(value);
    
    if (value <= root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    
    return root;
}

node* find_node(node* root, int value){
    if (root->data == value)
        return root;
    
    if (value <= root->data)
        return find_node(root->left, value);
    else
        return find_node(root->right, value);
}

void print_pre_order(node* tree){
    if (tree){
        cout << tree->data << endl;
        print_pre_order(tree->left);
        print_pre_order(tree->right);
    }
}

int main(){
    node* tree;
    node temp;
    int node_count;
    int value;

    cin >> node_count;
    
    while(node_count--){
        cin >> value;

        tree = insert(tree, value);
    }

    cin >> value;
    tree = find_node(tree, value);
    print_pre_order(tree);

    
    return 0;
}
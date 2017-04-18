#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int max(int a, int b)
{
  return (a >= b)? a: b;
}  

struct node
{
    int data;                 //Data element
    struct node * left;       //Pointer to left node
    struct node * right;      //Pointer to right node
}node;

struct node * newnode(int element)
{
    struct node * temp=(struct node *)malloc(sizeof(node));
    temp->data=element;
    temp->left=temp->right=NULL;
    return temp;
}

int maxDepth(struct node* node) 
{
    if (node==NULL) 
        return 0;
    else
    {
        // compute the depth of each subtree 
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        // use the larger one
        return max(lDepth, rDepth) + 1;
    }
} 

int diameter(struct node * node, int* height){
    if(node == NULL){
        *height = 0;
        return 0;
    }

    int leftHeight = 0;
    int rightHeight = 0;

    int leftDiameter = diameter(node->left, &leftHeight);
    int rightDiameter = diameter(node->right, &rightHeight);

    *height = max(leftHeight, rightHeight) + 1;

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
    
}

int main(){
    int nodes_count;
    int value;
    struct node* root;
    struct node* actualNode;

    cin >> nodes_count >> value;

    root = newnode(value);

    for(int i=0; i<nodes_count - 1; i++){
        string directions;
        cin >> directions >> value;

        actualNode = root;

        for (int c=0; c<directions.size(); c++){
            if (directions[c] == 'L'){
                if (actualNode->left == NULL)
                    actualNode->left = newnode(value);
                actualNode = actualNode->left;
            }
            else{
                if (actualNode->right == NULL)
                    actualNode->right = newnode(value);
                actualNode = actualNode->right;
            }
        }
    }

    int height = 0;
    cout << diameter(root, &height) << endl;

    return 0;
}
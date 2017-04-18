#include <bits/stdc++.h>
using namespace std;
#define LL long long int

/*
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
        if (lDepth > rDepth) 
            return(lDepth+1);
        else 
            return(rDepth+1);
    }
} 

*/
int main(){
    int nodes_count;
    int value;
    int leftDeep = 0;
    int rightDeep = 0;

    cin >> nodes_count >> value;

    for(int i=0; i<nodes_count - 1; i++){
        string directions;
        cin >> directions >> value;

        if (directions[0] == 'L' && directions.size() > leftDeep)
            leftDeep = directions.size();
        else if (directions[0] == 'R' && directions.size() > rightDeep)
            rightDeep = directions.size();
    }
    cout << leftDeep + rightDeep + 1 << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define LL long long int

typedef struct node{
    node* child(26); //1 for each english alfabet
    int weight;
} node;

node* create_node(){
    node *temp;
    temp = (node *) malloc(sizeof(node));
    for(int i=0;i<26;i++)
        temp->child[i]=NULL;
    temp->weight = 0;
}

node* add_string (node* root, string s, int weight){
    char c;

    if (s.size() == 0) return NULL;
    
    if (!root->child[s[0] - 'a']){
        // stopped here
    }
    for (int i=0; i<s.size(); i++){
        c = s[i];

    }
}

int main(){

    int database_len, queries_len;
    int weight;
    string s;
    
    cin >> base_len >> queries_len;
    
    while(base_len--){
        cin >> s >> weight;
    }
    
    while(queries_len--){
        cin >> s;
    }


    return 0;
}


/*
struct node{
    struct node *child[26];
    int isleaf;
};

struct node *getnode()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    for(int i=0;i<26;i++)
    temp->child[i]=NULL;
    temp->isleaf=-1;
}
void add(struct node * root,string s,int k)
{
    struct node *temp;
    temp=root;
    int ind;
    for(int i=0;i<s.size();i++)
    {
        ind=s[i]-'a';
        if(temp->child[ind]==NULL)
        {
            temp->child[ind]=getnode();
            temp->isleaf=k;
        }
        if(temp->isleaf<k)
            temp->isleaf=k;
        temp=temp->child[ind];
        }
    temp->isleaf=0;

}
int ans;
void add1(struct node * root,string s)
{
    ans=-1;
    int ind;
    struct node *temp=root;
    for(int i=0;i<s.size();i++)
    {
        ind=s[i]-'a';
        if(temp->child[ind]==NULL)
        {
            ans=-1;
            break;
        }
        ans=temp->isleaf;
        temp=temp->child[ind];
    }
}
int main()
{
    int i,j,n,q,k;
    scanf("%d%d",&n,&k);
    string s;
    struct node * root=NULL;
    root=getnode();
    for(i=1;i<=n;i++)
    {
        cin>>s>>k;
        add(root,s,k);
    }
    while(q--)
    {
        cin>>s;
        add1(root,s);
        printf("%d\n",ans);
    }
    return 0;
}
*/
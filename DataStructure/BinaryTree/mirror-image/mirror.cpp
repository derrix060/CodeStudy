#include <bits/stdc++.h>
using namespace std;
#define LL long long int

string change (string direction){
    string rtn = "";

    for (int i=0; i<direction.size(); i++){
        if (direction[i] == 'R')
            rtn += 'L';
        else
            rtn += 'R';
    }
    
    return rtn;
}

int search(int idx, map<int,string> tree){
    string value = tree[idx];
    map<int,string>::iterator it;

    value = change(value);

    for (it=tree.begin(); it != tree.end(); ++it){
        if (it->second == value)
            return it->first;
    }
    return -1;
}

int main(){
    int tree_size;
    int search_size;
    map<int,string> tree;
    int father, actual;
    char direction;

    cin >> tree_size >> search_size;

    tree[1] = "";
    for (int i=0; i<tree_size - 1; i++){
        cin >> father >> actual >> direction;
        tree[actual] = tree[father] + direction;
    }

    for (int i=0; i<search_size; i++){
        cin >> actual;
        cout << search(actual, tree) << endl;
    }
    
    return 0;
}
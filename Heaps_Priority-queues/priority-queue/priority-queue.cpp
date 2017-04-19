#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int main(){
    int size;
    int number;
    int operation;
    priority_queue<int> pq;

    cin >> size;

    while (size--){
        cin >> number;

        pq.push(number);
    }

    cin >> size;

    while(size--){
        cin >> operation;

        if (operation == 2){
            cout << pq.top() << endl;
            pq.pop();
        }
        else{
            cin >> number;
            pq.push(number);
        }
    }
    
    return 0;
}
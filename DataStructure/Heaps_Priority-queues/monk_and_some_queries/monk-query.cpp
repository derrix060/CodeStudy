#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int main(){
    priority_queue<int> mxPq;
    priority_queue<int> minPq;
    int a[100002];

    // complete the array with zeroes;
    memset(a, 0, sizeof(a));

    int query_size;
    int opt;
    int num;

    cin >> query_size;

    while(query_size--){
        cin >> opt;

        switch(opt){
            case 1:
                // add
                cin >> num;
                mxPq.push(num);
                minPq.push(-num);
                a[num] ++;
                break;

            case 2:
                // remove
                cin >> num;
                if(a[num])
                    a[num] --;
                else
                    cout << -1 << endl;

                break;

            case 3:
                // max
                while(mxPq.size() && a[mxPq.top()] == 0){
                    // this number don't exist any more
                    mxPq.pop();
                }

                if(mxPq.size()){
                    //has element
                    cout << mxPq.top() << endl;
                }else{
                    // empty
                    cout << -1 << endl;
                }
                break;

            case 4:
                // min
                while(minPq.size() && a[-minPq.top()] == 0){
                    // this number don't exist any more
                    minPq.pop();
                }

                if (minPq.size()){
                    cout << -minPq.top() << endl;
                
                }else{
                    cout << -1 << endl;
                }
                break;
        }
    }
    
    return 0;
}
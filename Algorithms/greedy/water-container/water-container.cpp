#include <bits/stdc++.h>
using namespace std;
#define LL long long int

const int MAX = 10001;

int main(){
    int case_count;
    int conteiner_capacity;
    int bottles_capacity;
    int bottles_count;
    int actual_capacity;
    int num_bottles;
    int bottles[MAX];

    cin >> case_count;

    while(case_count--){
        cin >> bottles_count >> conteiner_capacity;
        
        // clear bottles
        
        actual_capacity = 0;
        num_bottles = 0;

        for (int i=0; i<bottles_count; i++){
            cin >> bottles[i];
        }

        sort(bottles, bottles + bottles_count);

        int actualIdx = 0;
        
        for (int i=0; i<bottles_count; i++){
            actual_capacity += bottles[i];

            if (actual_capacity > conteiner_capacity) break;

            num_bottles++;
        }

        cout << num_bottles << endl;



    }
    
    return 0;
}
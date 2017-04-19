#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int main(){
    int test_case;
    set<int> numbers;
    int number_count;
    int distinct;
    int number;

    cin >> test_case;

    while(test_case--){
        // renew map
        numbers.clear();

        cin >> number_count >> distinct;

        while(number_count--){
            cin >> number;
            numbers.insert(number);
        }

        number = numbers.size();

        if (distinct > number)
            cout << "Bad" << endl;
        else if (distinct == number)
            cout << "Good" << endl;
        else
            cout << "Average" << endl;

    }
    
    return 0;
}
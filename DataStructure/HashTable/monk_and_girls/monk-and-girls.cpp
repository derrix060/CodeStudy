#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(){
    int size;
    int idx;
    string name;

    cin >> size;
    map<int,string> names;

    while (size-- != 0){
        cin >> idx;
        cin >> name;
        names[idx] = name;
    }

    cin >> size;

    while (size-- != 0){
        cin >> idx;
        cout << names[idx] << endl;
    }

    return 0;
}
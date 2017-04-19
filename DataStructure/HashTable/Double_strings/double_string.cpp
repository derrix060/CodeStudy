#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int main(){
    int word_num;
    map<char,int> words;
    string word;
    bool canBeDoubleString;

    cin >> word_num;

    for(int i=0; i < word_num; i++){
        canBeDoubleString = false;
        words.clear();
        cin >> word;
        
        for(int j=0; j<word.size(); j++){
            char c = word[j];
            words[c] = 0;
        }
        
        for(int j=0; j<word.size(); j++){
            char c = word[j];
            words[c] ++;
            if (words[c] == 2){
                canBeDoubleString = true;
                break;
            }
        }

        if (canBeDoubleString){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}
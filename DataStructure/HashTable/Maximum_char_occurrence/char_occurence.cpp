#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int main(){
    string word;
    getline(cin, word);
    map<char,int> words;
    char answ;
    int times = 0;

    for (int i=0; i<word.size(); i++){
        char c = word[i];
        words[c] ++;
        if (words[c] > times || (words[c] == times) && c < answ){
            times = words[c];
            answ = c;
        }
    }

    // for each element in words
    /*
    for (map<char,int>::iterator character = words.begin(); character != words.end(); character ++){
        if (character->second > times){
            times = character->second;
            answ = character->first;
        }
    }
    */

    cout << answ << " " << times << endl;

    return 0;
}   
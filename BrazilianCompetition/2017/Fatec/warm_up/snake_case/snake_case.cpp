#include <bits/stdc++.h>

using namespace std;

#define si(a)				scanf("%d",&a)
#define sl(a)				scanf("%lld",&a)
#define pi(a)				printf("%d\n",a)
#define pl(a)				printf("%lld\n",a)
 
typedef long long			ll;
typedef vector<int>			vi;
typedef pair<int, int>		ii;
typedef vector<vi>			vvi;
typedef vector<ii>			vii;
 
#define fast_io				ios_base::sync_with_stdio(false);cin.tie(NULL)
#define SET(a,b)			memset(a,b,sizeof(a))	
#define forall(i,a,b)		for(int i=a; i<b; i++)
#define forrev(i,a,b)		for(int i=a; i>=b; i--)
#define forr(it,container)  for(auto it=container.begin(); it!=container.end(); it++)
#define w(t)				int t;si(t);while(t--)

vector<string> split_words(string word, string delimiters){
	vector<string> rtn;
	string s;
	char *cstr = new char[word.size()+1];
	strcpy(cstr, word.c_str());
	
	char *del = new char[delimiters.size()+1];
	strcpy(del, delimiters.c_str());
	
	char *p = strtok(cstr,del);
	
	while(p){
		s = p;
		rtn.push_back(s);
		p = strtok(NULL,del);
	}
	
	return rtn;
	
}


int main(){
    fast_io;

    string word;

    while(cin >> word){
        if (word == "class"){
            cout << word << " ";
            cin >> word;

            vector<string> words = split_words(word, "_");

            forall(i,0,words.size()){
                words[i][0] -= 32; //convert to uppercase, acording ASCII table
                cout << words[i];
            }
        }
        else{
            forall(i, 0, word.size()){
                if(word[i] >= 'A' && word[i] <= 'Z'){
                    cout << "_";
                    word[i] += 32;
                }
                cout << word[i];
            }
        }

        cout << "\n";
    }
    
    return 0;
}
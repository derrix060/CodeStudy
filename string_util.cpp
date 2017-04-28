#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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



int main ()
{
	// Split Word
  	string str ("Please split ,  this sentence into tokens");
  	string del (" ,");
  
  	vector<string> words = split_words(str, del);
  
  	for(auto s:words) cout << s << "\n";
  

	// Cast Str -> Number
	string numb = "1234";
	// can be stoi, stol, stoll, stof, stod, stold.
	int numb_int = stoi(numb);

	cout << numb_int + 1 << "\n";

	// Cast Number -> Str
	numb = to_string(numb_int);
	cout << numb << "\n";


	// Find
	string str ("There are two needles in this haystack with needles.");
	string str2 ("needle");

	// different member versions of find in the same order as above:
	size_t found = str.find(str2);
	if (found!=string::npos)
		cout << "first 'needle' found at: " << found << '\n';
		//out: first 'needle' found at: 14

	found=str.find("needles are small",found+1,6);
	if (found!=string::npos)
		cout << "second 'needle' found at: " << found << '\n';
		//out: second 'needle' found at: 44

	found=str.find("haystack");
	if (found!=string::npos)
		cout << "'haystack' also found at: " << found << '\n';
		//out: 'haystack' also found at: 30

	found=str.find('.');
	if (found!=string::npos)
		cout << "Dot found at: " << found << '\n';
		//out: Dot found at: 51

	str.replace(str.find(str2),str2.length(),"preposition");
	cout << str << '\n';
	//out: There are two prepositions in this haystack with needles.


	// Replace
	int myints[] = { 10, 20, 30, 30, 20, 10, 10, 20 };
  	vector<int> myvector (myints, myints+8);            // 10 20 30 30 20 10 10 20

  	replace (myvector.begin(), myvector.end(), 20, 99); // 10 99 30 30 99 10 10 99



	// Set
	#include <set>
	set<int> myset;
	set<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

	it=myset.find(20);
	myset.erase (it);
	myset.erase (myset.find(40));

	cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
	//out: myset contains: 10 30 50
	

	// Map
	#include <map>
	map<char,int> mapa;

	mapa['a'] = 10;
	mapa['b'] = 20;

	cout << mapa['a'] << "\n";
	//out: 10
	cout << mapa['c'] << "\n";
	//out: 0 ?


	// Stack
	#include <stack>
	stack<int> pilha;

	pilha.push(1);
	pilha.push(2);
	pilha.push(3);

	cout << pilha.top() << "\n";
	pilha.pop(); //remove top element
	//out: 3

	// Queue
	#include <queue>
	priority_queue<int> mypq;
	mypq.push(30);
	mypq.push(100);
	mypq.push(25);
	mypq.push(40);

	 cout << "Popping out elements...";
	while (!mypq.empty())
	{
		cout << ' ' << mypq.top();
		mypq.pop();
	}
	cout << '\n';
	//out: Popping out elements... 100 40 30 25



	// Pair
	#include <utility>

	pair <string,double> product1;                     // default constructor
	pair <string,double> product2 ("tomatoes",2.30);   // value init
	pair <string,double> product3 (product2);          // copy constructor

	product1 = make_pair(string("lightbulbs"),0.99);   // using make_pair (move)

	product2.first = "shoes";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	cout << "The price of " << product1.first << " is $" << product1.second << '\n';
	cout << "The price of " << product2.first << " is $" << product2.second << '\n';
	cout << "The price of " << product3.first << " is $" << product3.second << '\n';
  




	return 0;
}
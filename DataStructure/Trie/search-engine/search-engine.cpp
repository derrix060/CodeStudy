#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define fast_io				ios_base::sync_with_stdio(false);cin.tie(NULL)

int MAGIC_NUMBER =  97; // 97 in ASCII = 'a'
int ct = 0;

typedef struct node{
    node* child[26]; //1 for each english alfabet
    int weight;
} node;

node* create_node(){
    node *temp;
    temp = (node *) malloc(sizeof(node));
    for(int i=0;i<26;i++)
        temp->child[i]=NULL;
    temp->weight = 0;

    return temp;
}

void add_string (node* root, string s, int weight){
    char c;
    int idx;
    node* temp = root;

    for (int i=0; i<s.size();i++){
        c = s[i];
        idx = c - MAGIC_NUMBER;

        if (temp->child[idx] == NULL){
            temp->child[idx] = create_node();
        }

        temp = temp->child[idx];
        temp->weight = max(temp->weight, weight);
    }    
}

int max_weight(node* root, string s){
    node* temp = root;

    for (int i=0; i<s.size();i++){
        temp = temp->child[s[i] - MAGIC_NUMBER];
        if (temp == NULL) return -1;
    }

    return temp->weight;
}

int main(){
    fast_io;
    int database_len, queries_len;
    int weight;
    node* root = create_node();
    root->weight = -1;
    string s;
    
    cin >> database_len >> queries_len;
    
    while(database_len--){
        cin >> s >> weight;
        add_string(root, s, weight);
    }
    
    while(queries_len--){
        cin >> s;
        cout << max_weight(root, s) << endl;
    }


    return 0;
}



/*
    Best solution

    //by Tanmay Chaudhari
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//#pragma comment(linker, "/STACK:66777216")
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
 
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1 << " | ";__f(comma + 1, args...);
}
#else   
#define trace(...)
#endif
 
int trie[26 * 1000005], nxt[1000005][26], counter=1;
 
void insert(string s, int w)
{
	int cur = 1;
	for (int i = 0;i < int(s.size());i++)
	{
		trie[cur] = max(trie[cur], w);
		int to = s[i] - 'a';
		if (!nxt[cur][to])
			nxt[cur][to] = ++counter;
		cur = nxt[cur][to];
	}
	trie[cur] = max(trie[cur], w);
}
 
int query(string s)
{
	int cur = 1;
	for (int i = 0;i < int(s.size());i++)
	{
		int to = s[i] - 'a';
		if (nxt[cur][to] == -1)
			return -1;
		cur = nxt[cur][to];
	}
	return trie[cur];
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	fast_io;
	int n, q;
	cin >> n >> q;
	forall(i, 0, n)
	{
		string s;int w;
		cin >> s >> w;
		insert(s, w);
	}
	while (q--)
	{
		string s;
		cin >> s;
		int ans = query(s);
		if (ans == 0)cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}



*/
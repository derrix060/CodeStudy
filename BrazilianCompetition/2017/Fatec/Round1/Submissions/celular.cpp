#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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

static int charValTabLower[] =
{
	1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
	1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4
};

static int charValTabUpper[] =
{
	4, 5, 6, 4, 5, 6, 4, 5, 6, 4, 5, 6, 4, 5, 6,
	5, 6, 7, 8, 4, 5, 6, 5, 6, 7, 8
};


int main(){
	fast_io;

	string a;
	getline(cin,a);

	const char *data = a.data();
	const char *c = data;
	int res = 0;
	while (*c != '\0') {
		if (*c >= 'a' && *c <= 'z')
			res += charValTabLower[*c - 'a'];
		else if (*c >= 'A' && *c <= 'Z')
			res += charValTabUpper[*c - 'A'];
		else if (*c == ' ')
			res += 1;
		++c;
	}
	cout << res << "\n";

	return 0;
}
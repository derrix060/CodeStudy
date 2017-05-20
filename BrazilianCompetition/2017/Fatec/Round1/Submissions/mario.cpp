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


static char g_map[1000][1000];
static int g_width;
static int g_height;


bool step(int x, int y, int numSteps, int numVidas) {
	if (x < 0 || x >= g_width) return false;
	if (y < 0 || y >= g_height) return false;

	char sym = g_map[x][y];
	if (sym == 'z' || sym == 'x')
		return false;
	if (sym == 'T')
		return true;
	g_map[x][y] = 'z';
	if (numSteps == 4) {
		numVidas -= 1;
		numSteps = 0;
	}
	if (numVidas == 0)
		return false;
	++numSteps;
	if (step(x + 1, y, numSteps, numVidas) == true) { return true; }
	if (step(x - 1, y, numSteps, numVidas) == true) { return true; }
	if (step(x, y + 1, numSteps, numVidas) == true) { return true; }
	if (step(x, y - 1, numSteps, numVidas) == true) { return true; }
	return false;
}


int main(){
	fast_io;
	cin >> g_height >> g_width;
	int startX, startY;
	int lives;
	for (int h = 0; h < g_height; ++h) {
		for (int w = 0; w < g_width; ++w) {
			char c;
			cin >> c;
			g_map[w][h] = c;
			if (c == 'S') {
				startX = w;
				startY = h;
			}
		}
	}
	cin >> lives;

	bool result = step(startX, startY, 0, lives);
	if (result) {
		cout << "SIM";
	}
	else {
		cout << "NAO";
	}

	return 0;
}
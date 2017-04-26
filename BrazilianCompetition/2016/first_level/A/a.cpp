#include <bits/stdc++.h>

/*
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
*/

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


//Andando no tempo

int main(){
    fast_io;
    bool resp = false;
    int a, b, c;

    cin >> a >> b >> c;

    if ((a - b) == 0) resp = true;
    if ((a - c) == 0) resp = true;
    if ((b - c) == 0) resp = true;
    if ((a + b - c) == 0) resp = true;
    if ((a + c - b) == 0) resp = true;
    if ((b + c - a) == 0) resp = true;


    if (resp)
        cout << "S\n";
    else
        cout <<"N\n";

    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    
    return 0;
}
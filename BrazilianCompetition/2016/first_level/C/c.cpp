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

// return the cost
int swap_container(int *navio_i[][], iii, jji, iif, jjf){
    int tot = *navio_i[iii][jji] + *navio_i[iif][jjf];

    int temp = *navio_i[iii][jji];

    *navio_i[iii][jji] = *navio_i[iif][jjf];
    *navio_i[iif][jjf] = temp;
    return tot;
}

int solve(){
    

}


//containers
int main(){
    fast_io;
    int navio_i[2][4];
    int navio_f[2][4];

    forall(i,0,2){
        forall(j,0,4){
            cin >> navio_i[i][j];
        }
    }
    forall(i,0,2){
        forall(j,0,4){
            cin >> navio_f[i][j];
        }
    }



    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    
    return 0;
}
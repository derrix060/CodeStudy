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


typedef struct container{
	int espaco_disponivel = 8;
	vector<int> pallets;
} container;

container containers[50];

void insere_pallet(int num, int size){
	forall(i, 0, 50){
		if (containers[i].espaco_disponivel >= size){
			containers[i].pallets.push_back(num);
			containers[i].espaco_disponivel -= size;
			break;
		}
	}
}

void procura_pallet(int num){
	forall(i, 0, 50){
		string retirar = "";
		forrev(j, containers[i].pallets.size() - 1, 0){
			if (containers[i].pallets[j] == num){
				cout << "Pallet " << num << " Container " << i + 1;

				if (retirar.size() == 0){
					cout << " TOPO\n";
				}
				else{
					cout << " Retirar" << retirar << "\n";
				}

				break;
			}
			else{
				retirar += " ";
				char numStr[20];
				sprintf(numStr, "%d", containers[i].pallets[j]);
				//string numStr = to_string(containers[i].pallets[j]);
				retirar += numStr;
			}
		}
	}
}


int main(){
	fast_io;

	string numeros;
	int actual = 0;

	getline(cin, numeros);

	const char *c = numeros.data();
	while (*c != '\0'){
		if (*c >= '0' && *c <= '9'){
			int num = *c - '0';
			actual++;
			insere_pallet(actual, num);
		}
		++c;
	}

	while (cin >> actual){
		procura_pallet(actual);
	}

	return 0;
}
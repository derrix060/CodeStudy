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



int main(){
	fast_io;

	string codigo_barras;
	int pos_atual_boleto = 0;
	int pos_atual_barras = 0;

	int codigoBoleto[100];
	getline(cin, codigo_barras);

	//b
	pos_atual_boleto = 0;
	forall(i, 0, 3){
		codigoBoleto[pos_atual_boleto++] = codigo_barras[pos_atual_barras++] - '0';
	}

	//m
	pos_atual_boleto = 3;
	codigoBoleto[pos_atual_boleto] = codigo_barras[pos_atual_barras++] - '0'; //moeda
	
	//c
	codigoBoleto[18] = codigo_barras[pos_atual_barras++] - '0'; //primeiro campo livre c
	pos_atual_barras++; // ponto

	//c
	pos_atual_boleto = 19;
	forall(i, 1, 5){
		codigoBoleto[pos_atual_boleto++] = codigo_barras[pos_atual_barras++] - '0';
	}

	pos_atual_barras += 2; //ignora dig campo 1 e espaco

	//d
	pos_atual_boleto = 23;
	forall(i, 0, 5){
		codigoBoleto[pos_atual_boleto++] = codigo_barras[pos_atual_barras++] - '0';
	}

	pos_atual_barras++; //ignora ponto

	//d2
	pos_atual_boleto = 28;
	forall(i, 5, 10){
		codigoBoleto[pos_atual_boleto++] = codigo_barras[pos_atual_barras++] - '0';
	}

	pos_atual_barras += 2; //ignora digi campo 2 e espaco
	//e
	pos_atual_boleto = 33;
	forall(i, 0, 5){
		codigoBoleto[pos_atual_boleto++] = codigo_barras[pos_atual_barras++] - '0';
	}

	pos_atual_barras++; //ignora ponto

	//e2
	pos_atual_boleto = 38;
	forall(i, 5, 10){
		codigoBoleto[pos_atual_boleto++] = codigo_barras[pos_atual_barras++] - '0';
	}

	pos_atual_barras += 4; //ignora digi campo 2 e espaco 3 o K e outro espaço

	//f
	pos_atual_boleto = 4;
	forall(i, 0, 4){
		codigoBoleto[pos_atual_boleto++] = codigo_barras[pos_atual_barras++] - '0';
	}

	//v
	pos_atual_boleto = 8;
	forall(i, 0, 10){
		codigoBoleto[pos_atual_boleto++] = codigo_barras[pos_atual_barras++] - '0';
	}

	/*
	FINAL LEITURA

	*/

	int posCalc = 2;
	int digito = 0;
	for (int i = 42; i >= 0; --i) {
		digito += codigoBoleto[i] * posCalc;
		if (++posCalc > 9)
			posCalc = 2;
	}

	digito = 11 - (digito % 11);
	if (digito == 0 || digito > 9)
		digito = 1;

	cout << digito;
	cout << "\n";
	return 0;
}
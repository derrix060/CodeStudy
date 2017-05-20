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

typedef struct equipe{
	int fatec;
	int id;
	int problemas_resolvidos;
	int tempo;
}equipe;

bool equipe_compare(equipe e1, equipe e2) {

	if (e1.problemas_resolvidos == e2.problemas_resolvidos){
		return e1.tempo < e2.tempo;
	}
	return e1.problemas_resolvidos > e2.problemas_resolvidos;
}

bool fatecs_compare(equipe e1, equipe e2){
	if (e1.fatec == e2.fatec){
		return equipe_compare(e1, e2);
	}
	return e1.fatec > e2.fatec;
}

int main(){
	fast_io;

	int vagas, qtde_fatecs, qtde_equipes;
	vector<equipe> equipes;
	vector<int> equipes_class;
	cin >> vagas >> qtde_fatecs >> qtde_equipes;

	// Leitura
	forall(i, 0, qtde_equipes){
		equipe e;
		cin >> e.fatec >> e.id >> e.problemas_resolvidos >> e.tempo;
		equipes.push_back(e);
	}

	// Melhores equipes de cada faculdade

	sort(equipes.begin(), equipes.end(), fatecs_compare);
	int f_atual = 0;
	forall(i, 0, qtde_equipes){
		equipe e = equipes[i];
		if (e.fatec != f_atual){
			equipes_class.push_back(e.id);
			f_atual = e.fatec;
		}
	}

	vagas -= equipes_class.size();

	// Resto das vagas para os melhores
	sort(equipes.begin(), equipes.end(), equipe_compare);

	int act_idx = 0;
	while (vagas){
		equipe e = equipes[act_idx];
		int flag = 0;

		forall(i, 0, equipes_class.size()){
			if (equipes_class[i] == e.id){
				flag = 1;
				break;
			}
		}

		if (flag != 1){
			equipes_class.push_back(equipes[act_idx].id);
			vagas--;
		}

		act_idx++;

	}

	sort(equipes_class.begin(), equipes_class.end());

	forall(j, 0, equipes_class.size() - 1){
		cout << equipes_class[j] << ", ";
	}
	cout << equipes_class[equipes_class.size() - 1] << ".\n";

	return 0;
}
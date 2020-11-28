#include <bits/stdc++.h>

using namespace std;
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PI; 
typedef pair<LL,LL> PLL;
typedef unsigned long long ULL;

#define IOSWORK ios::sync_with_stdio(0); cin.tie(0)
#define FOR(x, b, e) for(int x = b; x<= (e); x++)
#define FORD(x, b, e) for(int x = b; x>= (e); x--)
#define REP(x, n) for(int x = 0; x<(n); ++x)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define VAR(v, n) typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

#define PB push_back
#define IN insert
#define ST first
#define ND second
#define INF 2000000011
#define MOD 1000000007

#define MAXSIZE 

int main(){

	FOR(i,1,50000){
		cout<<i<<"\n";
		system("./gen >_in");
		
		system("./brut <_in >_brout");
		system("./wzor <_in >_wzout");
		
		if(system("diff _wzout _brout")!=0){
			system("cat _in");
			cout<<"NIE DZIALA";
			return 0;
		}
	}
	
	return 0;
}

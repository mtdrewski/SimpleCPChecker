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
	IOSWORK;
	
	srand(time(0));
	int l=rand()%100000;

	cout<<l<<" "<<rand()%100000+l+1<<"\n";
	return 0;
}

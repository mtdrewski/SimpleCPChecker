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
	
	int z = 1;
	cout<<z<<"\n";
	while(z--){
		int n=20;
		int m=100;
		cout<<n<<" "<<m<<"\n";

		set<PI> pary;
		FOR(i,1,n-1)
			pary.IN({i,i+1});
		while(SIZE(pary)<m){
			int t1=rand()%n+1;
			int t2=rand()%n+1;
			while(t2==t1)
				t2=rand()%n+1;
			pary.IN({min(t1,t2),max(t1,t2)});
		}
		for(auto x: pary)
			cout<<x.ST<<" "<<x.ND<<" "<<rand()%10+1<<"\n"; 
		int s=7;
		cout<<s<<"\n";
		set<int> term;
		while(SIZE(term)<s)
			term.IN(rand()%n+1);
		for(auto x:term)
			cout<<x<<" ";
		cout<<"\n";
	}
	return 0;
}

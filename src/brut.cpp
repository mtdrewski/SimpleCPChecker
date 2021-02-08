#include <bits/stdc++.h>
 
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef pair<int,int> PI; 
typedef pair<LL,LL> PLL;
typedef unsigned long long ULL;
typedef pair<double,double> PD;
 
#define FOR(x, b, e) for(int x = b; x<= (e); x++)
#define FORD(x, b, e) for(int x = b; x>= (e); x--)
#define REP(x, n) for(int x = 0; x<(n); ++x)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
 
#define PB push_back
#define IN insert
#define ST first
#define ND second
#define INF 2000000011
#define MOD 1000000007

#define MAXS 300010

pair<long,long> arr[MAXS];
int n;

int detonate(int mask){
    
    VI det(n);
    queue<int> toDet;
    REP(i,n){
        if((1<<i)&mask){
            toDet.push(i);
            det[i]=1;
        }
    }

    while(!toDet.empty()){
        int x=toDet.front();
        toDet.pop();
        
        LL r1=arr[x].ST+arr[x].ND;
        int p=x+1;
        while(p<n&&arr[p].ST<=r1){
            if(!det[p]){
                toDet.push(p);
                det[p]=1;
            }
            p++;
        }
        
        p=x-1;
        r1=arr[x].ST-arr[x].ND;
        while(p>=0&&arr[p].ST>=r1){
            if(!det[p]){
                toDet.push(p);
                det[p]=1;
            }
            p--;
        }
    }

    int m1=0;
    REP(i,n){
        if(det[i])
            m1|=1<<i;
    }
    return m1;
}

int main(){

    ios::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    REP(i,n)
        cin>>arr[i].ST>>arr[i].ND;
    
    set<int> wyn;
    REP(i,1<<n)    //brut, brutow, detonujemy odpowiednia maske elementow
        wyn.insert(detonate(i));
    cout<<SIZE(wyn)<<"\n";
}
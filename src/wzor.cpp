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

#define MAXS 500010

LL suf[MAXS];  //odpowiednio to bedzie prefix dla {[p,p]},{[p-1,p],[p-1,p-1]} itd...
LL arr[MAXS];
vector<LL> poz;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int p=0;
    FOR(i,1,n){
        cin>>arr[i];
        if(arr[i]!=0){
            poz.PB(i);
            p++;
        }
    }
    
    FORD(i,n,1)
        suf[i]=suf[i+1]+arr[i];
    
    if(suf[1]<0){
        cout<<"-1\n";
        return 0;
    }
    if(p==0){
        cout<<"0\n";
        return 0;
    }
    
    map<LL,LL> mapa;
    LL digDp=INF;

    FORD(i,p-1,0){
        
        if(suf[poz[i]]>=0){

            digDp=0;
            auto it=mapa.upper_bound(suf[poz[i]]);//szukamy {s,val}, t. ze s>suf[poz[i]]
            if(it!=mapa.begin()){
                it--;       //wtedy staje sie ze s<=suf[poz[i]] 
                digDp=it->second;
            }
            if(i){
                LL val=digDp+poz[i]-poz[i-1];
                if(mapa.empty())
                    mapa.insert({suf[poz[i]],val});
                else{
                    it=mapa.upper_bound(suf[poz[i]]);
                    if(it!=mapa.begin()){
                        it--;
                        if(it->second>=val)
                            continue;
                        it++;
                    }
                    
                    while(it!=mapa.end()&&it->second<=val)
                        it=mapa.erase(it);
                    mapa.insert({suf[poz[i]],val});                    
                }
            }
        }
    }
    cout<<poz[p-1]-poz[0]-digDp<<"\n";

}
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
 
#define MAXS 10000000

vector<PI> zegar;
VI values;


void moveother(int p){
    if(p==SIZE(values))
        return;
    if(values[p]==1){
        FOR(i,1,zegar[p].ST-1){
            values[p]++;
            cout<<zegar[p].ND<<" 1\n";
            moveother(p+1);
        }
    }
    else{
        FORD(i,zegar[p].ST-1,1){
            values[p]--;
            cout<<zegar[p].ND<<" -1\n";
            moveother(p+1);
        }
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;    
    cin>>n;
    REP(i,n){
        int t1;
        cin>>t1;
        zegar.PB({t1,i+1});    
    }

    FOR(i,1,SIZE(zegar)-1){
        if(zegar[i].ST%2==0)
            swap(zegar[i],zegar[0]);
    }

    if(SIZE(zegar)==1||zegar[0].ST%2){    
        cout<<"NIE\n";
        return 0;
    }
    
    
    values.resize(SIZE(zegar),1);   

    FOR(i,1,zegar[0].ST-1){
        values[0]++;
        cout<<zegar[0].ND<<" 1\n";
        moveother(2);
    }
    values[1]++;
    cout<<zegar[1].ND<<" 1\n";
    moveother(2);

    FORD(i,zegar[0].ST-1,1){
        if(values[1]==2){
            FOR(j,2,zegar[1].ST-1){
                values[1]++;
                cout<<zegar[1].ND<<" 1\n";
                moveother(2);
            }
        }
        else if(values[1]==zegar[1].ST){
            FORD(j,zegar[1].ST-1,2){
                values[1]--;
                cout<<zegar[1].ND<<" -1\n";
                moveother(2);
            }
        }
        values[0]--;
        cout<<zegar[0].ND<<" -1\n";
        moveother(2);
    }

    FORD(j,zegar[1].ST-1,1){
        values[1]--;
        cout<<zegar[1].ND<<" -1\n";
        moveother(2);
    }
    

}
/*

    cout<<"START: "<<zegar[0].ST<<" "<<zegar[1].ST<<"\n";
cout<<"{"<<values[0]<<","<<values[1]<<"}\n";
*/
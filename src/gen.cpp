#include <bits/stdc++.h>
#include "oi.h"

using namespace std;

int main(int argc, char *argv[]){

	ios::sync_with_stdio(0);
	cin.tie(0);

	oi::Random randGen;
	randGen.setSeed(clock());
	
	int z=1;
	cout<<z<<"\n";
	while(z--){
		int n=400,m=400;
		cout<<n<<" "<<m<<"\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(randGen.rand()%3==0)
					cout<<"x";
				else
					cout<<".";
			}
			cout<<"\n";
		}
	}
	return 0;
}
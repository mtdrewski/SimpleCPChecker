#include <bits/stdc++.h>
#include "oi.h"

using namespace std;

int main(int argc, char *argv[]){

	ios::sync_with_stdio(0);
	cin.tie(0);

	oi::Random randGen;
	randGen.setSeed(clock());
	
	int n=16;
	cout<<n<<"\n";
	set<long long> bomby;
	
	while((int)(bomby.size())<n)
		bomby.insert(randGen.randUInt());
	for(auto x:bomby)
		cout<<x<<" "<<randGen.randUInt()<<"\n";


	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN =1e6 +7;
const int MAXLG = log2(MAXN) + 3; 
const int MOD = 1e9 + 7;

int ans[MAXN],from,to;
vector<int> v = {113,131,197,199,311,337,373,719,733,919,971,991,1193,1931,3119,3779,7793,7937,9311,9377,11939,19391,19937,37199,39119,71993,91193,93719,93911,99371,193939,939391,393919,939193,391939,919393,199933 ,999331,993319,933199,331999,319993};

int main(int argc, char const *argv[]){
 	freopen("uva.in","r",stdin);
	for (int i = 0; i < v.size(); ++i) ans[v[i]] = 1;
	for (int i = 1; i < MAXN; ++i) ans[i]+=ans[i-1];
	while(scanf("%d",&from) && from!=-1){
		scanf("%d",&to);
		int k=ans[to]-ans[from-1];
		if(k==0) printf("No Circular Primes.\n");
		else if(k==1) printf("1 Circular Prime.\n");
		else printf("%d Circular Primes.\n",k );
	}
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN =1e6 +5;
const int MAXLG = log2(MAXN) + 3; 
const int MOD = 1e9 + 7;

int prime[MAXN],primeList[MAXN],nbDiv[MAXN],ans[MAXN],t,n;

void sieve(){
	for (int i = 2; i < MAXN; ++i)
		if(!prime[i]){
			for(int j=i+i; j < MAXN; j+=i)
				prime[j]=1;
		}
	int idx=0;
	for (int i = 2; i < MAXN; ++i){
		if(!prime[i]) primeList[idx++] = i;
	}
}

void divisors(){
	nbDiv[1]=1;
	for (int i = 2; i < MAXN; ++i){
		int nbdiv=1;
		int nbr=i; 
		for (int idx = 0; primeList[idx]*primeList[idx] <=nbr ; ++idx){
			int count = 0;
			while(nbr%primeList[idx]==0){
				count++;
				nbr/=primeList[idx];
			}
			nbdiv*=count+1;
		}
		if(nbr>1) nbdiv*=2;
		nbDiv[i]=nbdiv;
	}
}

int main(int argc, char const *argv[]){
	sieve();
	//printf("1\n");
	divisors();
	//printf("2\n");
	ans[1]=1;
	for (int i = 2; i < MAXN; ++i){
		ans[i] = (nbDiv[i]>=nbDiv[ans[i-1]]) ? i:ans[i-1];
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}

	return 0;
}
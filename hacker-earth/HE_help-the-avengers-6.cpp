#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int Sieve = 1e6 +5;
const int MAXN  = 32000+5;
int BIT[MAXN],prime[Sieve],isPrime[MAXN];
int t,N,q,x,y;
char s[2];
set<int> PL;

void sieve(){
	for (int i = 2; i*i < Sieve; ++i)
		if(!prime[i])
			for (int j = i*i; j <Sieve ; j+=i)
				prime[j]=1;
	for (int i = 2; i < Sieve; ++i)
		if(!prime[i]) PL.insert(i);
}


void build(){
	for (int i = 1; i <= N; ++i){
		int j = i + (i & (-i));
		if(j<=N) BIT[j]+=BIT[i];
	}
}

void update(int i, int val){
	while(i<=N){
		BIT[i]+=val;
		i+= i & -i;
	}
}

ll get(int i){
	ll res = 0;
	while(i>0){
		res+=BIT[i];
		i-=i&-i;
	}
	return res;
}


int get_range(int f,int t){
	return get(t) - get(f-1);
}


int main(int argc, char const *argv[]){
	freopen("uva.in","r",stdin);
	sieve();
	scanf("%d",&t);
	while(t--){
		memset(BIT,0,sizeof(BIT));
		memset(isPrime,0,sizeof(isPrime));
		scanf("%d",&N);
		for (int i = 1; i <= N; ++i){
			scanf("%d",&x);
			if(PL.find(x)!=PL.end()) BIT[i]=1,isPrime[i]=1;
		}
		build();
		scanf("%d",&q);
		while(q--){
			scanf("%s%d%d",s,&x,&y);
			if(s[0]=='A'){
				printf("%d\n", get_range(x,y));
			}
			else {
				if(!isPrime[x] && PL.find(y)!=PL.end()){
					isPrime[x]=1;
					update(x,1);
				}
				else if(isPrime[x] && PL.find(y) == PL.end() ){
					isPrime[x]=0;
					update(x,-1);
				}
			}
		}

	}
	return 0;
}
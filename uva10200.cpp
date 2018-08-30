#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int Sieve =100030045;
const int MAXN = 1e4 + 5;
const int MAXLG = log2(MAXN) + 3; 
const int MOD = 1e9 + 7;

int prime[Sieve],a,b;
int pre[MAXN];

void sieve(){
	prime[0]=prime[1]=1;
	for (int i = 2; i * i  < Sieve; ++i)
		if(!prime[i]){
			for(int j=i*i; j < Sieve; j+=i)
				prime[j]=1;
		}

	for (int i = 0; i < MAXN; ++i){
		pre[i+1] = pre[i];
		if(!prime[i*i + i + 41]) ++pre[i+1];
	}
}


int main(int argc, char const *argv[]){
	//freopen("uva.in","r",stdin);
	//freopen("uva.out","w",stdout);
	sieve();
	while(scanf("%d%d",&a,&b) == 2){
		double c=round((pre[b+1] - pre[a]) *100 * 100 / (double)(b - a +1)) / 100.0 ;
		printf("%.2lf\n",c);
	}
	return 0;
}
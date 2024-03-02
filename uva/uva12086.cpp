#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN =1e6 +5;
const int MAXLG = log2(MAXN) + 3; 
const int MOD = 1e9 + 7;

ll BIT[MAXN],arr[MAXN];
int N,x,y;
char s[3];

void build(){
	for (int i = 1; i <= N; ++i)
		BIT[i] = arr[i];
	for (int idx = 1; idx <= N; ++idx){
		int  idx2 = idx + (idx & (-idx));
		if(idx2 <= N) BIT[idx2]+=BIT[idx];
	}
}

void update(int i,int val){
	while(i<=N){
		BIT[i]+=val;
		i+= i & -i;
	}
}

ll get(int i){
	ll ret = 0;
	while(i>0){
		ret+=BIT[i];
		i-= i & -i;
	}
	return ret;
}

ll get_range(int l,int r){
	return get(r) - get(l-1);
}


int main(int argc, char const *argv[]){
	freopen("uva.in","r",stdin);
	int cas=1;
	while(scanf("%d",&N) && N){
		if(cas!=1) printf("\n");
		printf("Case %d:\n",cas++);
		memset(BIT,0,sizeof(BIT));
		for (int i = 1; i <= N; ++i) scanf("%d",arr + i);
		build();
		while(scanf("%s",s) && s[0]!='E'){
			scanf("%d%d",&x,&y);
			if(s[0]=='S'){
				update(x,-arr[x]);
				arr[x]=y;
				update(x,y);
			}
			else printf("%lld\n", get_range(x,y));
		}
		
	}

	
	return 0;
}

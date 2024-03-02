#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define L(ID) (ID << 1)
#define R(ID) ((ID << 1) +1)
#define M(X,Y) ((X+Y) >> 1)
const int MAXN = 1e5 +5;
const int MAXLG = 30;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int arr[MAXN],N,Q,L,R,seg[MAXN * 4];
char s[2];

void build(int id ,int l ,int r){
	if(l==r){
		seg[id]=arr[l];
	}else{
		int m=M(l,r);
		build(L(id),l,m);
		build(R(id),m+1,r);
		seg[id] = seg[L(id)] * seg[R(id)];
	}
}
void update(int i, int v, int id , int l ,int r){
	if(l==r){
		if(v!=0) arr[i] = (v>0) ? 1: -1;
		else arr[i]=v;
		seg[id]=arr[i];
	}else{
		int m=M(l,r);
		if(i<=m) update(i,v,L(id),l,m);
		else update(i,v,R(id),m+1,r);
		seg[id] = seg[L(id)] * seg[R(id)];
	}
}

int get(int x, int y, int id, int l , int r){
	if(x > r  ||  y < l) return 1;
	if(x <= l && r <= y) return seg[id];
	int m=M(l,r);
	return get(x,y,L(id),l,m) * get(x,y,R(id),m+1,r);
}

int main(int argc, char const *argv[]){
	freopen("uva.in","r",stdin);
	while(scanf("%d%d",&N,&Q) == 2){
		memset(arr,0,sizeof(arr));
		memset(seg,0,sizeof(seg));
		for (int i = 1; i <=N; ++i){
			scanf("%d",arr + i);
			if(arr[i]!=0)
			arr[i]= (arr[i]>0)? 1 : -1;
		}
		build(1,1,N);
		for (int i = 0; i < Q; ++i){
			scanf("%s%d%d",s,&L,&R);
			if(s[0]=='C'){
				update(L,R,1,1,N);
			}
			else{
				ll ans=get(L,R,1,1,N);
				if(ans==0) printf("0");
				else if(ans>0) printf("+");
				else printf("-");
			}
		}
		printf("\n");
	}
	return 0;
}
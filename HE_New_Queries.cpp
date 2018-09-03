#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define L(ID) (ID << 1)
#define R(ID) ((ID << 1) +1)
#define M(X,Y) ((X+Y) >> 1)
const int MAXN = 1e5 +5;

int N,Q,l,r,cmd;
ll v,ans;
pair<ll,ll> T[MAXN * 4];
ll a[MAXN];

pair<ll,ll> merge(pair<ll,ll> a, pair<ll,ll> b){
	return {
		max(a.first,b.first),
		max(a.second,b.second)
	};
}

void build(int id , int l ,int r){
	if( l == r){
		T[id]={-1,-1};
		if(a[l]%2 == 1) T[id].first = a[l];
		else T[id].second = a[l];
	}else{
		int m=M(l,r);
		build(L(id),l,m);
		build(R(id),m+1,r);
		T[id] = merge(T[L(id)],T[R(id)]);
	}
}

void update(int i,ll v, int id,int l ,int r){
	if(l == r ){
		a[l]=v;
		T[id]={-1,-1};
		if(a[l]%2 == 1) T[id].first = a[l];
		else T[id].second = a[l];
	}else{
		int m=M(l,r);
		if(i<=m) update(i,v,L(id),l,m);
		else update(i,v,R(id),m+1,r);
		T[id] = merge(T[L(id)],T[R(id)]);
	}
}

pair<ll,ll> get(int x, int y, int id,int l,int r){
	if(x>r ||y < l) return {-1,-1};
	if(x<=l && r<= y) return T[id];
	int m=M(l,r);
	return merge(get(x,y,L(id),l,m),get(x,y,R(id),m+1,r));
}


int main(int argc, char const *argv[]){
	scanf("%d%d",&N,&Q);
	for (int i = 1; i <= N; ++i){
		scanf("%lld",a + i);
	}
	build(1,1,N);
	while(Q--){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d%lld",&l,&v);
			update(l,v,1,1,N);
		}
		else{
			scanf("%d%d",&l,&r);
			pair<ll,ll> p = get(l,r,1,1,N); 
			if(cmd == 2) ans= p.second;
			else ans= p.first;
			if(ans!=-1) printf("%lld\n", ans);
			else printf("DNE\n");
		}
	}
	return 0;
}
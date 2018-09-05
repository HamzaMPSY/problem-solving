#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define L(ID) (ID << 1)
#define R(ID) ((ID << 1) +1)
#define M(X,Y) ((X+Y) >> 1)
const int MAXN = 1e6 +5;
const int INF = 0x3f3f3f3f;

int arr[MAXN],seg[4*MAXN],n,t,q,L,R;

int combined(int i , int j){
	if(i==INF) return j;
	if(j==INF) return i;
	if(arr[i] < arr[j]) return i;
	else if(arr[i] > arr[j]) return j;
	else return (i<j) ? j:i;
}


void build(int id , int l ,int r){
	if(l==r){
		seg[id] = l; 
	}else{
		int m = M(l,r);
		build(L(id),l,m);
		build(R(id),m+1,r);
		seg[id] = combined(seg[L(id)],seg[R(id)]);
	}
}

int get (int x, int y , int id ,int l , int r){
	if(r<x || y<l) return INF;
	if(x<=l && r<=y) return seg[id];
	int m=M(l,r);
	return combined(get(x,y,L(id),l,m),get(x,y,R(id),m+1,r));
}


int main(int argc, char const *argv[]){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for (int i = 1; i <=n ; ++i){
			scanf("%d",arr + i);
		}
		build(1,1,n);
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&L,&R);
			printf("%d\n", get(L,R,1,1,n));
		}
	}
	
	return 0;
}
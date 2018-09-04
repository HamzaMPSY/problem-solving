#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define L(ID) (ID << 1)
#define R(ID) ((ID << 1) +1)
#define M(X,Y) ((X+Y) >> 1)
const int MAXN =2e5 +7;
const int MAXLG = log2(MAXN) + 3; 


int arr[MAXN],N,Q,L,R,cmd,seg[MAXN * 4];
ll z;
string s;

void build(int id , int l , int r){
	if(l==r){
		seg[id]=arr[l];
	}else{
		int m=M(l,r);
		build(L(id),l,m);
		build(R(id),m+1,r);
		seg[id]=seg[L(id)] + seg[R(id)];
	}
}

void update(int i ,int v,int id ,int l , int r){
	if(l==r){
		seg[id]=arr[l]=v;
	}else{
		int m=M(l,r);
		if(i<=m) update(i,v,L(id),l,m);
		else update(i,v,R(id),m+1,r);
		seg[id]=seg[L(id)] + seg[R(id)];
	}
}

int get(int x, int y , int id , int l , int r){
	if(x>r ||y < l) return 0;
	if(x<=l && r<= y) return seg[id];
	int m=M(l,r);
	return get(x,y,L(id),l,m) + get(x,y,R(id),m+1,r);
}



int main(int argc, char const *argv[]){
	freopen("uva.in","r",stdin);
	scanf("%d%d",&N,&Q);
	for (int i = 1; i <=N ; ++i){
		scanf("%lld",&z);
		s=to_string(z);
		if(s[0]==s[s.size()-1]) arr[i] = 1;
	}
	build(1,1,N);
	while(Q--){
		scanf("%d",&cmd);
		if(cmd == 1){
			scanf("%d%d",&L,&R);
			printf("%d\n", get(L,R,1,1,N));
		}
		else {
			scanf("%d%lld",&L,&z);
			s=to_string(z);
			if(s[0]==s[s.size()-1] && arr[L]== 0){
				update(L,1,1,1,N);
			}
			else if(s[0]!=s[s.size()-1] && arr[L] == 1){
				update(L,0,1,1,N);
			}
		}
	}
	return 0;
}
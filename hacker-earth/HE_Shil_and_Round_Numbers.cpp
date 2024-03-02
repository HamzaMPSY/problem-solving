#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN =2e5 +7;
const int MAXLG = log2(MAXN) + 3; 


int BIT[MAXN],N,Q,L,R,cmd;
ll z;
string s;


void build(){
	int j;
	for (int i = 1; i <= N; ++i){
		j=i + (i & (-i));
		if(j<=N) BIT[j]+=BIT[i];
	}

}

void update(int i , int val){
	while(i<=N){
		BIT[i]+=val;
		i+= i & (-i);
	}
}

int get(int i){
	int sum=0;
	while(i>0){
		sum+=BIT[i];
		i-= i & (-i);
	}
	return sum;
}


int main(int argc, char const *argv[]){
	freopen("uva.in","r",stdin);
	scanf("%d%d",&N,&Q);

	for (int i = 1; i <=N ; ++i){
		scanf("%lld",&z);
		s=to_string(z);
		if(s[0]==s[s.size()-1]) BIT[i] = 1;
	}
	build();
	while(Q--){
		scanf("%d",&cmd);
		if(cmd == 1){
			scanf("%d%d",&L,&R);
			printf("%d\n", get(R) - get(L-1));
		}
		else {
			scanf("%d%lld",&L,&z);
			s=to_string(z);
			if(s[0]==s[s.size()-1] && get(L) - get(L-1)== 0){
				update(L,1);
			}
			else if(s[0]!=s[s.size()-1] && get(L) - get(L-1) == 1){
				update(L,-1);
			}
		}
	}
	return 0;
}
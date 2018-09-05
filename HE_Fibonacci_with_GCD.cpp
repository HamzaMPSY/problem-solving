#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define L(ID) (ID << 1)
#define R(ID) ((ID << 1) +1)
#define M(X,Y) ((X+Y) >> 1)
const int MAXN = 1e6 +5;
const int MAXLG = 30;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
struct mat{
	int a[2][2];
	mat(){
		a[0][0]=a[0][1]=a[1][0]=1;
		a[1][1]=0;
	}
	mat operator*(const mat &m) const {
    mat ret;
    for(int i = 0; i < 2; ++i)
      for(int j = 0; j < 2; ++j) {
        int &sum = ret.a[i][j] = 0;
        for(int k = 0; k < 2; ++k) {
          sum = ( sum + a[i][k] * 1LL * m.a[k][j] ) % MOD;
        }
      }
    return ret;
  }
};


int T[MAXN][MAXLG],N,Q,x,L,R,ans;


void build(){
	for(int j = 1; j <= MAXLG; j++) 
        for(int i = 0; i <= N - (1 << j); i++)
            T[i][j] = __gcd(T[i][j - 1], T[i + (1 << (j - 1))][j - 1]);
}


int get(int L, int R){
	int answer = 0;
    for(int j = MAXLG; j >= 0; j--) {
        if(L + (1 << j) - 1 <= R) {
            answer = __gcd(answer, T[L][j]);
            L += 1 << j;
        }
    }
    return answer;
}



mat bp(mat m, int p) {
  if(p == 1) return m;
  mat tmp = bp(m, p / 2);
  tmp = (tmp * tmp);
  return (p%2 == 0) ? tmp : (tmp * m);
}


int main(int argc, char const *argv[]){

	scanf("%d%d",&N,&Q);
	for (int i = 0; i < N; ++i){
		scanf("%d",&x);
		T[i][0]= x;
	}
	build();
	for (int i = 0; i < Q; ++i){
		scanf("%d%d",&L,&R);
		ans=get(L-1,R-1);
		mat m;
		if(ans>1)
			m=bp(m,ans-1);
		ans= m.a[0][0];
        printf("%d\n",ans);
	}
	return 0;
}

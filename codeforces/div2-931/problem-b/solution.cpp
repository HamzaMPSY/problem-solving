#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int T,N,i,j,N2,ans2;
vector<int> ans(MAXN,INF);
int coins[5] = {1,3,6,10,15};

void preprocess(){
    ans[0] = 0;
    for (int i = 1; i < MAXN; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                ans[i] = min(ans[i], ans[i - coin] + 1);
            }
        }
    }
}

int main(int argc, const char** argv) {
    freopen("in.in","r",stdin);
    preprocess();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        printf("%d\n",ans[N]);
    }
    return 0;
}
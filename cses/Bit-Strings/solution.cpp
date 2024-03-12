#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e6 + 1;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N;
int ans = 1;
int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        ans = (ans % MOD * 2) % MOD;
    }
    printf("%d", ans);
    return 0;
}

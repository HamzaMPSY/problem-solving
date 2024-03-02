#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e6 + 7;
const int INF = 0x3f3f3f3f;

ll N;

void solve(ll N)
{
    printf("%lld ", N);
    if (N == 1)
        return;
    if (N % 2 == 0)
        return solve(N / 2);
    return solve(3 * N + 1);
}

int main(int argc, const char **argv)
{
    // freopen("in.in", "r", stdin);
    scanf("%lld", &N);
    solve(N);
    printf("\n");
    return 0;
}

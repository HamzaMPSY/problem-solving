#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 2e5 + 7;
const int INF = 0x3f3f3f3f;

int N, T[MAXN];

void solve()
{
    ll cnt = 0, dif;
    for (int i = 1; i < N; i++)
    {
        dif = T[i] - T[i - 1];
        if (dif < 0)
        {
            cnt -= dif;
            T[i] -= dif;
        }
    }
    printf("%lld\n", cnt);
}

int main(int argc, const char **argv)
{
    // freopen("in.in", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", T + i);
    }
    solve();
    return 0;
}

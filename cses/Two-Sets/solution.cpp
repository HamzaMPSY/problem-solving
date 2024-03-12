#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll N;
set<ll> ans1, ans2;
void solve()
{
    ll sum = (N * 1LL * (N + 1)) >> 1;
    if (sum % 2)
    {
        printf("NO\n");
    }
    else
    {
        ll set_sum = sum >> 1;
        while (N > 0)
        {
            if (set_sum >= N)
            {
                ans1.insert(N);
                set_sum -= N;
            }
            else
            {
                ans2.insert(N);
            }
            N--;
        }

        printf("YES\n");
        printf("%d\n", (int)ans1.size());
        for (auto a : ans1)
        {
            printf("%lld ", a);
        }
        printf("\n%d\n", (int)ans2.size());
        for (auto a : ans2)
        {
            printf("%lld ", a);
        }
    }
}

int main(int argc, const char **argv)
{
    // freopen("in.in", "r", stdin);
    scanf("%lld", &N);
    solve();
    return 0;
}

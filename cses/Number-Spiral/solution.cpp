#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int T, x, y;
ll ans;
int main(int argc, const char **argv)
{
    // freopen("in.in", "r", stdin);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &x, &y);
        if (x >= y)
        {
            if (x % 2 == 0)
            {
                ans = x * 1LL * x + 1;
                ans -= y;
            }
            else
            {
                ans = (x - 1) * 1LL * (x - 1);
                ans += y;
            }
        }
        else
        {
            if (y % 2)
            {
                ans = y * 1LL * y + 1;
                ans -= x;
            }
            else
            {
                ans = (y - 1) * 1LL * (y - 1);
                ans += x;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int T, N, M, x;
set<int> ans;
int main(int argc, const char **argv)
{
    // freopen("in.in", "r", stdin);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &M);
        ans.clear();
        while (N--)
        {
            scanf("%d", &x);
            ans.insert(x);
        }
        while (M--)
        {
            scanf("%d", &x);
            ans.insert(x);
        }
        printf("%d\n", ans.size());
        for (int a : ans)
        {
            printf("%d ", a);
        }
        printf("\n");
    }
    return 0;
}
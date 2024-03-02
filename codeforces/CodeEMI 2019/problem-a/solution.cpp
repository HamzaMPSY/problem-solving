#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int T, N, x;
set<int> ans;
int main(int argc, const char **argv)
{
    // freopen("in.in", "r", stdin);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        ans.clear();
        while (N--)
        {
            scanf("%d", &x);
            ans.insert(x);
        }
        auto median = ans.begin();
        std::advance(median, ans.size() / 2);
        printf("%d\n", *median);
    }
    return 0;
}

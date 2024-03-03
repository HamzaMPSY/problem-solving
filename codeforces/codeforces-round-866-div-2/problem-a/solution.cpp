#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 100 + 7;
const int INF = 0x3f3f3f3f;

int T, cnt, len;
char s[MAXN];
int main(int argc, const char **argv)
{
    // freopen("in.in", "r", stdin);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        cnt = s[0] == '_' ? 1 : 0;
        len = strlen(s);
        cnt += s[len - 1] == '_' ? 1 : 0;
        for (int i = 1; i < len; ++i)
        {
            if (s[i] == s[i - 1] && s[i] == '_')
                ++cnt;
        }
        if (len == 1 && cnt == 0)
            ++cnt;
        printf("%d\n", cnt);
    }
    return 0;
}

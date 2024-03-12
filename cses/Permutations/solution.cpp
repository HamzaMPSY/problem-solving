#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int N;
int main(int argc, const char **argv)
{
    // freopen("in.in", "r", stdin);
    scanf("%d", &N);
    if (N == 3 || N == 2)
    {
        printf("NO SOLUTION\n");
    }
    else
    {

        for (int i = N - 1; i > 0; i -= 2)
        {
            printf("%d ", i);
        }

        for (int i = N; i > 0; i -= 2)
        {
            printf("%d ", i);
        }
    }
    return 0;
}

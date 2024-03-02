#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll A, B;
int T;

ll numberofLeapYears(ll year)
{

    return (year / 4) - (year / 100) + (year / 400);
}

ll solve()
{
    return numberofLeapYears(B) - numberofLeapYears(A - 1);
}
int main(int argc, char const *argv[])
{
    // freopen("in.in", "r", stdin);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &A, &B);
        printf("%lld\n", solve());
    }
    return 0;
}

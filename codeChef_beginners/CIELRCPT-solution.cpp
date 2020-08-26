#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define REP(i, a, b) for (i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

int main()
{
    int T, p;
    int i, result, t[12];

    rep(i, 12) t[i] = (1 << i); /* t[i] denotes pow(2,i) */

    assert(scanf("%d", &T) == 1);
    assert(1 <= T && T <= 5);
    while (T--)
    {
        assert(scanf("%d", &p) == 1);
        assert(1 <= p && p <= 100000);

        result = 0;
        for (i = 11; i >= 0; i--)
        {
            result += p / t[i]; /* p/t[i] (floor(p/t[i])) denotes the number of nemu i which Tomya orders */
            p %= t[i];       /* p decrease by used money */
        }

        printf("%d\n", result);
    }

    return 0;
}
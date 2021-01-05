// *********************
// @:YZQ
// @:2020/1/5
// @:https://blog.csdn.net/Galaxy_yr/article/details/93530583
// *********************

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int MaxSize = 15;
long long dp[2][1 << 15] = {0};
int cur;

int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) == 2)
    {
        if ((m * n) & 1)
        {
            printf("No solution\n");
            continue;
        }
        if (m < n)
            swap(m, n);
        memset(dp, 0, sizeof dp);
        cur = 0;
        dp[cur][(1 << n) - 1] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cur ^= 1;
                memset(dp[cur], 0, sizeof dp[cur]);
                for (int k = 0; k < (1 << n); k++)
                {
                    if (k & (1 << (n - 1)))
                        dp[cur][(k << 1) ^ (1 << n)] += dp[1 - cur][k];

                    if (i && !(k & (1 << (n - 1))))
                        dp[cur][(k << 1) ^ 1] += dp[1 - cur][k];

                    if(j && !(k & 1) && (k & (1 << (n  -1))))
                        dp[cur][(k << 1) ^ (1 << n) | (1 << 1) ^ 1] += dp[1 - cur][k];
                }
            }
        }

        printf("Path:%lld\n",dp[cur][(1 << n) - 1]);
    }
    return 0;
}
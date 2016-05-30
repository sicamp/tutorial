#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int const maxN = 1010;
long long const INF = 1e9 * 1e9;

int cost[maxN][maxN];
bool horse[maxN][maxN];
long long dp[maxN][maxN];

int n, m, k;

int main()
{
    freopen("spike.in", "r", stdin);
    freopen("spike.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &cost[i][j]);
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        horse[x - 1][y - 1] = true;
    }
    dp[0][0] = cost[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost[i + 1][j]);
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + cost[i][j + 1]);
            if (horse[i][j])
            {
                dp[i + 2][j + 1] = min(dp[i + 2][j + 1], dp[i][j] + cost[i + 2][j + 1]);
                dp[i + 1][j + 2] = min(dp[i + 1][j + 2], dp[i][j] + cost[i + 1][j + 2]);
            }
        }
    }
    printf("%lld\n", dp[n - 1][m - 1]);
    return 0;
}

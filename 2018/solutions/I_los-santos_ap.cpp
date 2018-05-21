#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;
ll const LLINF = 1e18 + 9;

ll dp[100100][2][2];
ll x[100100];
ll color[100100];
int last[100100][2];

int main() {
freopen("los-santos.in", "r", stdin);
freopen("los-santos.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n; ll d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> color[i];
    last[0][0] = last[0][1] = -1;
    for (int i = 0; i < n; i++) {
        if (!color[i]) last[i][0] = i; else last[i][0] = last[i - 1][0];
        if (color[i]) last[i][1] = i; else last[i][1] = last[i - 1][1];
    }
    for (int i = 0; i <= n; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = LLINF;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) for (int w = 0; w < 2; w++) for (int b = 0; b < 2; b++) {
        if (w && (!b || !color[i])) {
            dp[i + 1][0][b] = min(dp[i + 1][0][b], dp[i][1][b] + x[i] - x[last[i - 1][0]] + d * color[i]);
        }
        if (b && (!w || color[i])) {
            dp[i + 1][w][0] = min(dp[i + 1][w][0], dp[i][w][1] + x[i] - x[last[i - 1][1]] + d * (1 - color[i]));
        }
        if (!color[i] && !w) dp[i + 1][w + 1][b] = min(dp[i + 1][w + 1][b], dp[i][w][b]);
        if (color[i] && !b) dp[i + 1][w][b + 1] = min(dp[i + 1][w][b + 1], dp[i][w][b]);
    }
    cout << dp[n][0][0];
    return 0;
}

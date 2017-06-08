#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 22;
const int MAXK = 26;
int dp[MAXN][MAXK][2];
const int MOD = 1e9 + 7;

void upd(int & a, int x) {
    a += x;
    a %= MOD;
}
int main() {
    freopen("jokes.in", "r", stdin);
    freopen("jokes.out", "w", stdout);
    int n, k, m;
    cin >> n >> k >> m;
    vector<string> s(m);
    forn(i, m) {
        cin >> s[i];
        forn(j, 2)
            s[i][j] -= 'a';
    }
    forn(i, k) {
        dp[1][i][0] = 1;
    }
    for (int l = 1; l < n; ++l) {
        forn(i, k) {
            forn(j, k) {
                bool f = false;
                for (auto ss : s) {
                    if (ss[0] == i && ss[1] == j) {
                        f = true;
                        break;
                    }
                }
                if (f) {
                    upd(dp[l + 1][j][1], dp[l][i][0]);
                } else {
                    forn(x, 2) {
                        upd(dp[l + 1][j][x], dp[l][i][x]);
                    }
                }
            }
        }
    }
    int sum = 0;
    forn(i, k) {
        forn(x, 2) {
            upd(sum, dp[n][i][x]);
        }
    }
    cout << sum << '\n';
    return 0;
}


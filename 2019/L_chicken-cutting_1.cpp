#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cassert>
#include <bitset>
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> par;
int const INF = 1e9;
ld const eps = 1e-8;
ll const LLINF = 4 * (1e18) + 2;
int const PH = 257;
int const mod = 1e9 + 9;

par operator + (par const& a, par const& b) {
    return{ a.first + b.first, a.second + b.second };
}
par operator - (par const& a, par const& b) {
    return{ a.first - b.first, a.second - b.second };
}
ll operator % (par const& a, par const& b) {
    return (ll)a.first * b.second - (ll)a.second * b.first;
}
istream& operator >> (istream& in, par & a) {
    return (in >> a.first >> a.second);
}
ostream& operator << (ostream& ou, par a) {
    return (ou << a.first << ' ' << a.second << '\n');
}

namespace std {
    template <typename U, typename V>
    struct hash<std::pair<U, V>> {
        std::size_t operator ()(std::pair<U, V> const& a) const {
            using std::hash;
            using std::size_t;
            return size_t((1LL * hash<U>()(a.first) * PH + hash<V>()(a.second)) % mod);
        }
    };
}

inline uint64_t randll() {
    uint64_t res = rand();
    for (int i = 0; i < 3; i++) {
        res <<= 16;
        res += rand();
    }
    return res;
}

inline ld log(ld a, ld b) {
    return (log(b) / log(a));
}

ld len(par const& q) {
    return sqrt(q.first * q.first + q.second * q.second);
}

const int MAXN = 110, MAXM = 1000;
ld dp[MAXN][MAXN];
ld mind[MAXN][MAXN];
par pent[MAXN];
par dots[MAXM];

ld f(par p, par q, par r) {
    ld s = (q - r) % (p - r);
    return abs(s / len(p - q));
}

ld _min(ld a, ld b) {
    return (a - b > -eps) ? b : a;
}

int main() {
    freopen("chicken-cutting.in", "r", stdin);
    freopen("chicken-cutting.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> pent[i];
    for (int i = 0; i < m; i++) cin >> dots[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        dp[i][j] = -LLINF;
        mind[i][j] = LLINF;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < m; k++) {
        mind[i][j] = _min(mind[i][j], f(pent[i], pent[j], dots[k]));
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp[i][j] = -LLINF;
    for (int i = 0; i + 1 < n; i++) {
        dp[i][i + 1] = mind[i][i + 1];
    }
    for (int i = 0; i + 2 < n; i++) {
        dp[i][i + 2] = _min(mind[i][i + 1], _min(mind[i + 1][i + 2], mind[i][i + 2]));
    }
    for (int len = 0; len < n; len++) {
        for (int l = 0; l + len < n; l++) {
            int r = l + len;
            for (int k = l + 1; k < r; k++) {
                ld nw = _min(dp[l][k], dp[k][r]);
                nw = _min(nw, mind[l][r]);
                if (nw - dp[l][r] > eps) {
                    dp[l][r] = nw;
                }
            }
        }
    }
    cout << fixed << setprecision(8);
    cout << dp[0][n -1];
    return 0;
}

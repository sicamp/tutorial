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

const ll INF = 1e18;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e4;
const ll MAXC = 1e12;


int main() {
    freopen("factor.in", "r", stdin);
    freopen("factor.out", "w", stdout);
    //freopen("", "w", stderr);
    int n;
    cin >> n;
    assert(n >= 1 && n <= MAXN);
    vector<ll> mc(n + 1), dc(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> mc[i];
        assert(mc[i] >= 0 && mc[i] <= MAXC);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> dc[i];
        assert(dc[i] >= 0 && dc[i] <= MAXC);
    }
    vector<ll> d(n + 1, INF);
    d[1] = 0;
    vector<bool> used(n + 1, 0);
    forn(_, n) {
        int v = -1;
        for (int i = 1; i <= n; ++i) {
            if (!used[i] && (v == -1 || d[i] < d[v])) {
                v = i;
            }
        }
        assert(v != -1);
        used[v] = true;
        for (int m = 1; m <= n; ++m) {
            if (v * m <= n) {
                d[v * m] = min(d[v * m], d[v] + mc[m]);
            }
            if (v % m == 0) {
                d[v / m] = min(d[v / m], d[v] + dc[m]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << ' ';
    }
    cout << '\n';
     
    return 0;
}


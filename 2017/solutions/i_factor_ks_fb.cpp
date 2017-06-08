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

struct edge {
    int to;
    ll w;
};

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
    vector<vector<edge>> e(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * i <= n; ++j) {
            e[i].push_back({i * j, mc[j]});
            e[i * j].push_back({i, dc[j]});
        }
    }
    vector<ll> d(n + 1, INF);
    d[1] = 0;
    forn(_, n - 1) {
        bool was = false;
        for (int v = 1; v <= n; ++v) {
            for (auto ed : e[v]) {
                if (d[ed.to] > d[v] + ed.w) {
                    d[ed.to] = d[v] + ed.w;
                    was = true;
                }
            }
        }
        if (!was) {
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << ' ';
    }
    cout << '\n';
    return 0;
}


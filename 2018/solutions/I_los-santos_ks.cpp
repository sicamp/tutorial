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
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
const int MAXN = 1e5;

void upd(ll& a, const ll b) {
    a = min(a, b);
}

int main() {
    freopen("los-santos.in", "r", stdin);
    freopen("los-santos.out", "w", stdout);

    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll d;
    cin >> n >> d;
    assert(2 <= n && n <= 100000 && n % 2 == 0);
    assert(0 <= d && d <= 1000000000);
    vector<int> a(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        assert(1 <= a[i] && a[i] <= 1000000000);
        if (i > 0) {
            assert(a[i] > a[i - 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        assert(c[i] == 0 || c[i] == 1);
    }

    vector<ll> dp(4, INF), pr(4, INF);
    pr[0] = 0;
    vector<int> lst(2, -1);
    for (int i = 0; i < n; ++i) {
        dp = vector<ll>(4, INF);
        int oc = 1 - c[i];
        for (int o = 0; o < 2; ++o) {
            upd(dp[(1 << c[i]) + (o << oc)], pr[o << oc]);
            upd(dp[o << oc], pr[(1 << c[i]) + (o << oc)] + a[i] - lst[c[i]]);
        }
        upd(dp[0], pr[1 << oc] + a[i] - lst[oc] + d);

        lst[c[i]] = a[i];
        pr = dp;
    }

    cout << pr[0] << '\n';

    return 0;
}


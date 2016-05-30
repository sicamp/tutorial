/* cin : 0.55s
 * scanf : 0.47s
 * OK */
#include <cassert>
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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const ll INF = 1e18;
const ll MAXS = 1e15;
const int MAXC = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e6;
ll a[MAXN + 100];
ll pr[MAXN + 100];
ll msuf[MAXN + 100];


int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    //cin.sync_with_stdio(false);
    int n;
    ll s;
    scanf("%d%lld", &n, &s);
    //cin >> n >> s;
    assert(1 <= n && n <=  MAXN);
    assert(-MAXS <= s && s <= MAXS);
    forn(i, n) {
        scanf("%lld", &a[i]);
        //cin >> a[i];
        assert(-MAXC <= a[i] && a[i] <= MAXC);
    }
    pr[0] = 0;
    forn(i, n)
        pr[i + 1] = pr[i] + a[i];
    msuf[0] = -INF;
    forn(i, n + 1) {
        msuf[i + 1] = max(msuf[i], pr[n - i]);
    }
    int ans = 0;
    forn(i, n) {
        int l = 0;
        int r = n - i + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (msuf[n - i - m + 1] - pr[i] >= s) {
                l = m;
            } else {
                r = m;
            }
        }
        ans = max(ans, l);
    }
    cout << ans << '\n';

    return 0;
}


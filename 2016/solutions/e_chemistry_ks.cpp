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

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXI = 5e4 + 100;
const int MAXN = 100;

int main() {
    freopen("chemistry.in", "r", stdin);
    freopen("chemistry.out", "w", stdout);
    string s, t;
    int n, k;
    cin >>n >> k;
    cin >> s;
    cin >> t;
    assert(1 <= n && n <= MAXN);
    assert(1 <= k && k <= n - 1);
    assert(n == s.length());
    assert(n == t.length());
    forn(i, MAXI) {
        if (s == t) {
            printf("%d\n", i);
            return 0;
        }
        if (i % 2 == 0) {
            s = s.substr(1, k - 1) + s[0] + s.substr(k);
        } else {
            s = s.substr(0, k) + s[n - 1] + s.substr(k, n - k - 1);
        }
    }
    printf("-1\n");

    return 0;
}


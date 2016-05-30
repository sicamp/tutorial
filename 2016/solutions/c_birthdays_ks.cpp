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
const int MAXN = 1e5;

int sum(int i) {
    int res = 0;
    while (i > 0) {
        res += i % 10;
        i /= 10;
    }
    return res;
}
int main() {
    freopen("birthdays.in", "r", stdin);
    freopen("birthdays.out", "w", stdout);
    int k, len, p;
    int ans = 0;
    scanf("%d%d%d", &k, &len, &p);
    assert(1 <= k);
    assert(1 <= len);
    assert(len <= MAXN);
    assert(1 <= p);
    assert(p <= MAXN);
    for (int i = k; i < k + len; ++i) {
        if (sum(i) % p == 0)
            ans++;
    }
    cout << ans << '\n';


    return 0;
}


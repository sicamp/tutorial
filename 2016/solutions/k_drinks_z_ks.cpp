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
const int MAXN = 2500;
const int MAXL = 2 * MAXN + 100;
char s[MAXN + 100];
int tl = 0;
char t[MAXL];
char rt[MAXL];
int z[MAXL];
int ans = 0;

int maxz(char * s, int n) {
    clr(z);
    z[0] = 0;
    int l = 0, r = 0;
    int mx = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        mx = max(mx, z[i]);
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return mx;
}
void add(char c, int p) {
    t[tl++] = c;
    memcpy(rt, t, sizeof(char) * tl);
    reverse(rt, rt + tl);
    int mz = maxz(rt, tl);
    mz = min(p, mz);
    ans += p - mz;
}

int main() {
    freopen("drinks.in", "r", stdin);
    freopen("drinks.out", "w", stdout);
    //freopen("", "w", stderr);
    int n;
    scanf("%d", &n);
    assert(n >= 1 && n <= MAXN);
    int sum = 0;
    forn(i, n) {
        scanf("%s", s);
        int len = strlen(s);
        assert(len >= 1);
        sum += len;
        forn(j, len) {
            add(s[j], j + 1);
        }
        add('$', 0);
    }
    assert(sum <= MAXN);
    printf("%d\n", ans);
     
    return 0;
}


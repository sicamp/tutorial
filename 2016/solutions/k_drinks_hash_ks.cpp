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
const int point = 997;
const int MODS = 2;
const vector<int> MOD = {1e9 + 7, 1e9 + 9};
char s[MAXN + 100];

struct mhash {
    ll v[MODS];
    mhash() {
        clr(v);
    }
    mhash(char c) {
        forn(i, MODS)
            v[i] = c % MOD[i];
    }
    mhash operator * (ll d) const {
        mhash res;
        forn(i, MODS)
            res.v[i] = v[i] * d % MOD[i];
        return res;
    }
    mhash operator + (const mhash &o) const {
        mhash res;
        forn(i, MODS)
            res.v[i] = (v[i] + o.v[i]) % MOD[i];
        return res;
    }
    bool operator < (const mhash & o) const {
        forn(i, MODS) {
            if (v[i] != o.v[i])
                return v[i] < o.v[i];
        }
        return false;
    }
};
set<mhash> hashes;
void add(char * s, int len) {
    mhash h;
    forn(i, len) {
        h = h * point + mhash(s[i]);
        hashes.insert(h);
    }
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
            add(s + j, len - j);
        }
    }
    assert(sum <= MAXN);
    printf("%d\n", hashes.size());
     
    return 0;
}


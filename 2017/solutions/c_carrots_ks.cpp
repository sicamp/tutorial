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
const int MAXN = 110;

int t[MAXN][MAXN];

int n, m;
bool get(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    return t[x][y];
}

void fail() {
    cout << "no\n";
    exit(0);
}

int main() {
    freopen("carrots.in", "r", stdin);
    freopen("carrots.out", "w", stdout);

    cin >> n >> m;
    forn(i, n) {
        forn(j, m) {
            cin >> t[i][j];
        }
    }
    forn(i, n) {
        forn(j, m) {
            if (!t[i][j])
                continue;
            if (get(i - 1, j - 1) || get(i - 1, j + 1)) {
                fail();
            }
            if (get(i - 1, j) && get(i, j - 1) || get(i, j - 1) && get(i + 1, j) || get(i + 1, j) && get(i, j + 1) || get(i, j + 1) && get(i - 1, j)) {
                fail();
            }
        }
    }
    cout << "yes\n";

    return 0;
}


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
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0);
const int MAXN = 1e5;
const int MAXC = 1e4;

struct point {
    ld x, y;
    point operator + (const point & o) const {
        return {x + o.x, y + o.y};
    }
    point operator - (const point & o) const {
        return {x - o.x, y - o.y};
    }
    point operator * (ld d) const {
        return {x * d, y * d};
    }
    point rot(ld a) const { //counter-clockwise
        return {x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)};
    }
    void read() {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        assert(abs(xx) <= MAXC);
        assert(abs(yy) <= MAXC);
        x = xx, y = yy;
    }
    ld len() const {
        return sqrt(x * x + y * y);
    }
    ld distTo(const point & o) const {
        return ((*this) - o).len();
    }
    void print() const {
        cerr << fixed << setprecision(10) << x << ' '<< y << '\n';
    }
} p[MAXN + 100], t[MAXN + 100];

int n;

void add(int x, point p) {
    for (; x < n; x = x | (x + 1)) {
        t[x] = t[x] + p;
    }
}
point get(int x) {
    point res = {0, 0};
    for (; x >= 0; x = (x & (x + 1)) - 1) {
        res = res + t[x];
    }
    return res;
}

int main() {
    freopen("robohand.in", "r", stdin);
    freopen("robohand.out", "w", stdout);
    //freopen("", "w", stderr);
    scanf("%d", &n);
    assert(n >= 1 && n <= MAXN);
    p[0] = {0, 0};
    forn(i, n) {
        p[i + 1].read();
    }
    forn(i, n) {
        p[i] = p[i + 1] - p[i];
        assert(p[i].x != 0 || p[i].y != 0);
        t[i] = {0, 0};
    }
    forn(i, n) {
        add(i, p[i]);
    }
    int q;
    scanf("%d", &q);
    forn(i, q) {
        char c;
        scanf(" %c", &c);
        if (c == 'P') {
            int j, dl;
            scanf("%d%d", &j, &dl);
            assert(1 <= j && j <= n);
            assert(abs(dl) <= MAXC);
            j--;
            assert(p[j].len() + dl > EPS);
            point np = p[j] * ((p[j].len() + dl) / p[j].len());
            add(j, np - p[j]);
            p[j] = np;
        } else if (c == 'R') {
            int j, d;
            scanf("%d%d", &j, &d);
            assert(1 <= j && j <= n);
            assert(1 <= d && d <= 359);
            j--;
            point np = p[j].rot(d * PI / 180.0);
            add(j, np - p[j]);
            assert(abs(p[j].len() - np.len()) < EPS);
            p[j] = np;
        } else {
            int j1, j2;
            scanf("%d%d", &j1, &j2);
            assert(1 <= j2 && j2 <= n);
            assert(1 <= j1 && j1 <= n);
            j1--, j2--;
            cout << fixed << setprecision(20) << get(j1).distTo(get(j2)) << '\n';
        }
    }
    
    return 0;
}


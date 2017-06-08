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
const int MAXN = 2e5 + 100;
const int MAXC = 1e9;


struct seg {
    int l, r;
    bool operator < (const seg & o) const {
        return r < o.r;
    }
};


int main() {
    freopen("friendship.in", "r", stdin);
    freopen("friendship.out", "w", stdout);
    int n;
    cin >> n;
    assert(1 <= n && n <= 200000);
    vector<seg> s;
    forn(i, n) {
        int l, r;
        cin >> l >> r;
        assert(1 <= l && l <= r && r <= MAXC);
        s.push_back({l, r});
    }

    sort(s.begin(), s.end());
    int last = 0;
    vector<int> ans;
    for (auto x : s) {
        if (x.l > last) {
            ans.push_back(x.r);
            last = x.r;
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}


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

const int INF = 1e9;
const int MAXN = 1e5;

int cnt = 0;
vector<int> res;
int n;

void rec(int pos, int num, int onesLeft) {
    if (pos == -1) {
        if (cnt < 1000) {
            res.push_back(num);
        }

        cnt++;
    }
    if (onesLeft < pos + 1) {
        rec(pos - 1, num, onesLeft);
    }
    if (onesLeft == 0) {
        return;
    }
    num += 1 << pos;
    if (num <= n) {
        rec(pos - 1, num, onesLeft - 1);
    }
}

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> n >> k;
    assert(1 <= n && n <= 1e9);
    assert(0 <= k && k <= 10);
    rec(29, 0, k);
    cout << cnt << ' ';
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}


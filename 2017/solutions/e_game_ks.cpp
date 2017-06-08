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
const int MAXN = 1e5;
void factor(int a, vector<int> & d) {
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0) {
            d.push_back(i);
        }
    }
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    //freopen("", "w", stderr);
    int a, b;
    cin >> a >> b;
    vector<int> da, db;
    factor(a, da);
    factor(b, db);
    int common = 0;
    for (auto i : da)
        if (b % i == 0) {
            common++;
        }
    cout << da.size() - common << ' ' << db.size() - common << ' ' << common << '\n';
    return 0;
}


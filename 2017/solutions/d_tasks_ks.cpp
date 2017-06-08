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

string s[MAXN];

int main() {
    freopen("tasks.in", "r", stdin);
    freopen("tasks.out", "w", stdout);
    //freopen("", "w", stderr);
    char c;
    int cur = 0;
    cin >> noskipws;
    while (cin >> c) {
        cerr << int(c) << '\n';
        if (c != '\n') {
            if (cur > 0) {
                assert(c >= 'a' && c <= 'z');
            } else {
                assert(c >= '0' && c <= '9');
            }
            s[cur] += c;
        } else {
            cur++;
        }
    }
    int n = atoi(s[0].c_str());
    assert(n == cur - 1);
    assert(s[cur].length() == 0);
    vector<pair<string, string>> a;
    for (int i = 1; i <= n; ++i) {
        string t = s[i];
        sort(t.begin(), t.end());
        a.push_back({t, s[i]});
    }
    sort(a.begin(), a.end());
    for (auto p : a) {
        cout << p.second << '\n';
    }

    
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 510;

int m[MAXN][MAXN];

signed main()
{
#ifdef POSPELOV
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        m[x][y]++;
        mx = max(mx, m[x][y]);
    }
    cout << mx;
    return 0;
}
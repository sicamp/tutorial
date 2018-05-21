#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 30;

int n, k, a[N], b[N], c[N], d[N];
string s1, s2;
long long M = 1791791791, P = 29, p[N], h2, h[N], rez;

long long get_hash(int x,int y)
{
    return (((h[y] - h[x] * p[y - x] % M) + M) % M);
}

int main()
{
    freopen("camps.in", "r", stdin);
    freopen("camps.out", "w", stdout);
    p[0] = 1;
    h[0] = 0;
    cin >> n >> k;
    if (n < k)
        return 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i > 1)
            c[i - 1] = a[i - 1] - a[i];
    }
    for (int i = 1; i < n; i++)
        s1 += char((c[i] % 100 + 100) % 100);
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
        if (i > 1)
            d[i - 1] = b[i - 1] - b[i];
    }
    for (int i = 1; i < k; i++)
        s2 += char((d[i] % 100 + 100) % 100);
    for (int i = 1; i <= s1.size(); i++)
    {
        p[i] = (p[i - 1] * P) % M;
        h[i] = (h[i - 1] * P + s1[i - 1]) % M;

    }
    for (int i = 0; i < s2.size(); i++)
         h2 = (h2 * P + s2[i]) % M;
    for (int i = 0; i <= s1.size() - s2.size(); i++)
        if (get_hash(i, i + s2.size()) == h2)
        {
            cout << i + 1 << ' ';
            rez++;
        }
 
    return 0;
}

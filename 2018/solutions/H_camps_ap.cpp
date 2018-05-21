#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;

vector <int> all;
vector <int> s;
ll const mod = 1e9 + 9;
ll const p = 257;

vector <ll> h(vector <int> & a, ll & fn) {
    ll ch = 0;
    vector <ll> res;
    for (int i = 0; i < a.size(); i++) {
        res.push_back(ch);
        ch = ((ch * p % mod) + a[i]) % mod;
    }
    res.push_back(ch);
    fn = ch;
    return res;
}

ll st[200100];

inline ll substring(vector <ll> & a, int l, int r) {
    return (a[r] - (a[l] * st[r - l]) % mod + mod + mod) % mod;
}

int main() {
#ifdef yakutov
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("camps.in", "r", stdin);
    freopen("camps.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    st[0] = 1;
    for (int i = 1; i <= n; i++) st[i] = (st[i - 1] * p) % mod;
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        all.push_back(q);
    }
    for (int i = 0; i < t; i++) {
        int q;
        cin >> q;
        s.push_back(q);
    }
    vector <int> flat(t, 1);
    ll hflat;
    ll sh;
    vector <ll> ah = h(all, hflat);
    h(s, sh);
    h(flat, hflat);
    //cerr << sh << ' ' << hflat;
    for (int i = 0; i <= n - t; i++) {
        ll delta = all[i] - s[0];
        //cerr << substring(ah, i, i + t) << ' ' << hflat << ' ' << delta << endl;
        if ((sh + (hflat * delta) % mod) % mod == substring(ah, i, i + t)) cout << i + 1 << ' ';
    }
    return 0;
}

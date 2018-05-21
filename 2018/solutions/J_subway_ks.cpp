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

typedef long long ll;

const int MAXN = 1e5 + 100;

struct Tree {
    vector<ll> t;
    int size;

    Tree(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    void set_rec(int v, int l, int r, int p, int w) {
        if (r <= p || l > p) {
            return;
        }
        if (l == p && r == p + 1) {
            t[v] = w;
            return;
        }
        set_rec(2 * v + 1, l, (l + r) / 2, p, w);
        set_rec(2 * v + 2, (l + r) / 2, r, p, w);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void set(int p, int w) {
        set_rec(0, 0, size, p, w);
    }

    ll get_rec(int v, int l, int r, int lq, int rq) {
        if (r <= lq || rq <= l) {
            return 0;
        }

        if (lq <= l && r <= rq) {
            return t[v];
        }

        return get_rec(2 * v + 1, l, (l + r) / 2, lq, rq)
            + get_rec(2 * v + 2, (l + r) / 2, r, lq, rq);
    }

    ll get(int p) {
        return get_rec(0, 0, size, 0, p);
    }
};

vector<int> e[MAXN];
vector<Tree> paths;
vector<int> path, dist;
int center;


void setEdge(int u, int v, int w) {
    int p, d;
    if (u == center) {
        p = path[v];
        d = dist[v];
        assert(d == 0);
    } else {
        p = path[u];
        if (v == center) {
            d = dist[u];
            assert(d == 0);
        } else {
            assert(path[v] == p);
            assert(abs(dist[u] - dist[v]) == 1);
            d = max(dist[u], dist[v]);
        }
    }
    paths[p].set(d, w);
}

ll getDist(int u, int v) {
    ll du, dv;
    if (u == center) {
        du = 0;
    } else {
        du = paths[path[u]].get(dist[u] + 1);
    }
    if (v == center) {
        dv = 0;
    } else {
        dv = paths[path[v]].get(dist[v] + 1);
    }

    if (u == center || v == center || path[u] == path[v]) {
        return abs(du - dv);
    } else {
        return du + dv;
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int m = n - 1;
    vector<int> st(m), en(m), w(m);
    for (int i = 0; i < m; ++i) {
        cin >> st[i] >> en[i] >> w[i];
        st[i]--, en[i]--;
        e[st[i]].push_back(en[i]);
        e[en[i]].push_back(st[i]);
    }

    center = 0;
    for (int i = 0; i < n; ++i) {
        if (e[i].size() >= 3) {
            center = i;
            break;
        }
    }

    path.resize(n);
    dist.resize(n);

    for (int i = 0; i < e[center].size(); ++i) {
        int prev = center;
        int v = e[center][i];
        int d = 0;
        while (true) {
            path[v] = i;
            dist[v] = d;

            if (e[v].size() == 1) {
                break;
            }
            int nxt = e[v][0] == prev ? e[v][1] : e[v][0];
            prev = v;
            v = nxt;
            ++d;
        }
        paths.emplace_back(d + 1);
    }

    for (int i = 0; i < m; ++i) {
        setEdge(st[i], en[i], w[i]);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        char c;
        cin >> c;
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (c == 'c') {
            int w;
            cin >> w;
            setEdge(u, v, w);
        } else {
            assert(c == '?');
            cout << getDist(u, v) << '\n';
        }
    }

    return 0;
}

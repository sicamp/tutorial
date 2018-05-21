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

const int MAXN = 1e5 + 100;

struct edge {
    int to, col;
};

struct answer {
    int len, st;
    int col;

    bool operator < (const answer& o) const {
        if (len != o.len) {
            return len > o.len;
        }
        return st < o.st;
    }
};

vector<edge> edges[MAXN];

void addEdge(int u, int v, int col) {
    edges[u].push_back({v, col});
    edges[v].push_back({u, col});
}

using path = vector<int>;

path best = {0, 0, 0};

void upd(const answer& a, int v) {
    path newPath = {-a.len, a.st, v};
    if (newPath[1] > newPath[2]) {
        swap(newPath[1], newPath[2]);
    }

    best = min(best, newPath);
}

void upd(const answer& a, const answer& b) {
    if (a.len == -1 || b.len == -1) {
        return;
    }

    int totalLen = a.len + b.len;
    if (a.col != b.col) {
        totalLen++;
    }

    path newPath = {-totalLen, a.st, b.st};
    if (newPath[1] > newPath[2]) {
        swap(newPath[1], newPath[2]);
    }

    best = min(best, newPath);
}

answer dfs(int v, const edge& parent) {
    answer mxUp = {0, v, parent.col};
    answer mx = {-1, -1}, mx2 = {-1, -1};
    for (const auto& e : edges[v]) {
        if (e.to == parent.to) {
            continue;
        }
        answer res = dfs(e.to, {v, e.col});
        answer resUp = {res.col == parent.col ? res.len : res.len + 1, res.st, parent.col};
        mxUp = min(mxUp, resUp);

        upd(res, v);
        upd(res, mx);
        upd(res, mx2);
        if (res < mx) {
            mx2 = mx;
            mx = res;
        } else if (res < mx2) {
            mx2 = res;
        }
    }

    return mxUp;
}

int main() {
    freopen("subway2.in", "r", stdin);
    freopen("subway2.out", "w", stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        vector<int> b(k + 1);
        for (int j = 0; j < k + 1; ++j) {
            cin >> b[j];
            b[j]--;
        }
        for (int j = 0; j < k; ++j) {
            addEdge(b[j], b[j + 1], i);
        }
    }

    dfs(0, {-1, -1});
    cout << -best[0] << '\n' << best[1] + 1 << ' ' << best[2] + 1 << '\n';
    return 0;
}


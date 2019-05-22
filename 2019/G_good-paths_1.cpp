#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 10;

typedef long long ll;
vector <int> tree[MAXN];

ll cnt = 0;
bool was[MAXN];
void dfs(int u) {
    was[u] = true;
    cnt++;
    for (auto v : tree[u]) {
        if (!was[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v, s;
        cin >> u >> v >> s;
        u--;
        v--;

        if (s) {
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (!was[i]) {
            cnt = 0;
            dfs(i);
            ans += cnt * (cnt - 1) / 2;
        }
    }

    cout << ans;
    return 0;
}
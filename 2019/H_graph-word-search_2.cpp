#include <bits/stdc++.h>
using namespace std;

string s, pattern;
vector<vector<int>> g;
vector<int> ans;
vector<bool> used;
bool dfs(int v, int pos) {
  if (pos == pattern.size() - 1) {
    ans[pos] = v;
    return true;
  }
  ++pos;
  used[v] = true;
  for (int u: g[v]) {
    if (!used[u] && s[u] == pattern[pos] && dfs(u, pos)) {
      ans[pos - 1] = v;
      return true;
    }
  }
  used[v] = false;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  cin >> s;
  used.assign(n, false);
  g.resize(n);
  ans.resize(n, -1);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  cin >> pattern;
  for (int i = 0; i < n; ++i) sort(g[i].begin(), g[i].end());
  for (int i = 0; i < n; ++i) {
    if (s[i] == pattern[0] && dfs(i, 0)) {
      for (int v: ans) if (v >= 0) cout << v + 1 << ' ';
      return 0;
    }
  }
}
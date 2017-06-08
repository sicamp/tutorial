#include <bits/stdc++.h>
using namespace std;

int const N = 10100;
int const A = 26;

int link[N], len[N], cnt[N], go[N][A], sz = 0;

int get_node(int lnk, int ln) {
  link[sz] = lnk;
  len[sz] = ln;
  cnt[sz] = 1;
  fill(go[sz], go[sz] + A, -1);
  return sz++;
}

int append(int v, int x) {
  int n = get_node(0, len[v] + 1);
  while (v >= 0 && go[v][x] < 0) {
    go[v][x] = n;
    v = link[v];
  }
  if (v >= 0) {
    int u = go[v][x];
    if (len[v] + 1 == len[u]) {
      link[n] = u;
    } else {
      int w = sz++;
      link[w] = link[u];
      len[w] = len[v] + 1;
      copy(go[u], go[u] + A, go[w]);
      while (v >= 0 && go[v][x] == u) {
        go[v][x] = w;
        v = link[v];
      }
      link[u] = w;
      link[n] = w;
    }
  }
  return n;
}

int main() {
  freopen("plagiarism.in", "r", stdin);
  freopen("plagiarism.out", "w", stdout);
  static char a[N], b[N];
  scanf("%s%s", a, b);
  int v = get_node(-1, 0);
  for (int i = 0; a[i]; ++i) {
    v = append(v, a[i] - 'a');
  }
  {
    static int c[N], ord[N];
    for (int i = 0; i < sz; ++i) {
      ++c[len[i] + 1];
    }
    for (int i = 1; i < N; ++i) {
      c[i] += c[i - 1];
    }
    for (int i = 0; i < sz; ++i) {
      ord[c[len[i]]++] = i;
    }
    for (int i = sz - 1; i >= 0; --i) {
      int v = ord[i];
      if (v) {
        cnt[link[v]] += cnt[v];
      }
    }
  }
  long long ans = 0;
  for (int i = 0; b[i]; ++i) {
    v = 0;
    for (int j = i; b[j]; ++j) {
      v = go[v][b[j] - 'a'];
      if (v < 0) {
        break;
      }
      ans += cnt[v];
    }
  }
  cout << ans << '\n';
}


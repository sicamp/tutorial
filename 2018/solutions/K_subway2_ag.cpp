#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

inline int rnd(int x) {
  return myrand() % x;
}

#ifdef LOCAL
#define LLD "%lld"
#else
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#endif

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "subway2"

void precalc() {
}

const int maxn = 1e5 + 10;

int n;
vector<int> to[maxn];
vector<int> clr[maxn];

bool read() {
  int cnt;
  if (scanf("%d%d", &n, &cnt) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    to[i].clear();
    clr[i].clear();
  }
  for (int c = 0; c < cnt; ++c) {
    int k;
    scanf("%d", &k);
    for (int i = 0, pr = -1, a; i <= k; ++i, pr = a) {
      scanf("%d", &a);
      --a;
      if (i > 0) {
        to[a].pb(pr), to[pr].pb(a);
        clr[a].pb(c), clr[pr].pb(c);
      }
    }
  }
  return true;
}

int dp[maxn];
int vtx[maxn];
int res;
int av, au;

void upd(int v, int u, int cnt) {
  if (v > u) {
    swap(v, u);
  }
  if (cnt > res || (cnt == res && (v < av || (v == av && u < au)))) {
    res = cnt, av = v, au = u;
  }
}

void dfs(int v, int pr) {
  dp[v] = 0, vtx[v] = v;

  int pclr = -1;
  for (int i = 0; i < sz(to[v]); ++i) {
    int u = to[v][i];
    if (u == pr) {
      pclr = clr[v][i];
      continue;
    }
    dfs(u, v);
  }

  int mx[2] = {-1, -1};
  for (int i = 0; i < sz(to[v]); ++i) {
    int u = to[v][i], uc = clr[v][i];
    if (u == pr) {
      continue;
    }

    upd(vtx[u], v, dp[u]);

    int ndp = dp[u] + (uc == pclr ? 0 : 1);
    if (ndp > dp[v] || (ndp == dp[v] && vtx[u] < vtx[v])) {
      dp[v] = ndp;
      vtx[v] = vtx[u];
    }
    
    for (int it = 0; it < 2 && mx[it] != -1; ++it) {
      int w = to[v][mx[it]], wc = clr[v][mx[it]];
      upd(vtx[u], vtx[w], dp[u] + dp[w] + (uc == wc ? 0 : 1));
    }
    
    if (mx[0] == -1 || dp[u] > dp[to[v][mx[0]]] || (dp[u] == dp[to[v][mx[0]]] && vtx[u] < vtx[to[v][mx[0]]])) {
      mx[1] = mx[0];
      mx[0] = i;
    } else if (mx[1] == -1 || dp[u] > dp[to[v][mx[1]]] || (dp[u] == dp[to[v][mx[1]]] && vtx[u] < vtx[to[v][mx[1]]])) {
      mx[1] = i;
    }
  }
}

void solve() {
  res = 0, av = au = 0;
  dfs(0, -1);

  printf("%d\n%d %d\n", res, av + 1, au + 1);
}

int main() {
  srand(rdtsc());
  precalc();
  assert(freopen(TASK".out", "w", stdout));
  assert(freopen(TASK".in", "r", stdin));

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}



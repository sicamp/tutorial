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

int res, av, au;

void upd(int v, int u, int cnt) {
  if (v > u) {
    swap(v, u);
  }
  if (cnt > res || (cnt == res && (v < av || (v == av && u < au)))) {
    res = cnt, av = v, au = u;
  }
}

void dfs(int v, int pr, int pclr, int cur, int st) {
  upd(v, st, cur);

  for (int i = 0; i < sz(to[v]); ++i) {
    int u = to[v][i], c = clr[v][i];
    if (u == pr) {
      pclr = clr[v][i];
      continue;
    }
    int nxt = cur;
    if (pclr != -1 && pclr != c) {
      ++nxt;
    }
    dfs(u, v, c, nxt, st);
  }
}

void solve() {
  res = 0, av = au = 0;

  dfs(0, -1, -1, 0, 0);
  dfs(au, -1, -1, 0, au);

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



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
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stdout)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "security"

const int maxn = (int) 1e5 + 10;
const int k = 4;

int cost[1 << k];

void precalc() {
  for (int mask = 0; mask < (1 << k); ++mask) {
    cost[mask] = __builtin_popcount(mask);
  }
}

int n;
vector<int> to[maxn];
vector<int> clr[maxn];
int dp[1 << k][maxn];


bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    to[i].clear();
    clr[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a, --b, --c;
    to[a].pb(b), to[b].pb(a);
    clr[a].pb(c), clr[b].pb(c);
  }
  return true;
}

ll dfs(int v, int pr) {
  ll res = 0;

  dp[0][v] = 2;

  for (int i = 0; i < sz(to[v]); ++i) {
    int u = to[v][i], c = clr[v][i];
    if (u == pr) {
      continue;
    }
    res += dfs(u, v);
    for (int mask = 0; mask < (1 << k); ++mask) {
      dp[mask | (1 << c)][v] += dp[mask][u];
    }
  }

  for (int i = 0; i < sz(to[v]); ++i) {
    int u = to[v][i], c = clr[v][i];
    if (u == pr) {
      continue;
    }

    for (int umask = 0; umask < (1 << k); ++umask) {
      for (int vmask = 0; vmask < (1 << k); ++vmask) {
        int mask = (umask | vmask | (1 << c));
        ll cnt = dp[umask][u];
        cnt *= dp[vmask][v] - (((vmask >> c) & 1) ? (dp[vmask][u] + dp[vmask ^ (1 << c)][u]) : 0);
        res += cnt * cost[mask];
      }
    }
  }

  dp[0][v] = 1;

  return res;
}

void solve() {
  memset(dp, 0, sizeof(dp));
  ll res = dfs(0, -1);
  assert(res % 2 == 0);
  res /= 2;
  printf(LLD "\n", res);
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




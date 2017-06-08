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
#define TASK "brackets"

void precalc() {
}

const int maxn = 1e5 + 10;
const int inf = 1.01e9;

struct tree {
  int x[maxn * 4];
  int n;

  void build(int _n, char *s) {
    for (n = 1; n < _n + 1; n <<= 1);
    for (int i = 0, b = 0; i < n; ++i) {
      x[n + i] = b;
      if (i < _n) {
        b += (s[i] == '(' ? 1 : -1);
      }
    }
    for (int i = n - 1; i > 0; --i) {
      x[i] = min(x[2 * i], x[2 * i + 1]);
    }
  }

  int getMin(int v, int L, int R, int l, int r) {
    if (R <= l || r <= L) {
      return inf;
    }
    if (l <= L && R <= r) {
      return x[v];
    }
    int M = (L + R) / 2;
    return min(getMin(2 * v, L, M, l, r),
               getMin(2 * v + 1, M, R, l, r));
  }

  int getMin(int l, int r) {
    return getMin(1, 0, n, l, r);
  }

  int getVal(int p) {
    return x[n + p];
  }
};

int n, m;
char s[maxn];
int ql[maxn];
int qr[maxn];

bool read() {
  if (scanf("%s%d", s, &m) < 2) {
    return false;
  }
  n = strlen(s);
  for (int i = 0; i < m; ++i) {
    if (scanf("%d%d", &ql[i], &qr[i]) < 2) {
      return false;
    }
    --ql[i];
  }
  return true;
}

tree t;

void solve() {
  t.build(n, s);
  for (int i = 0; i < m; ++i) {
    int l = ql[i], r = qr[i];
    int stb = t.getVal(l);
    int minb = t.getMin(l, r + 1) - stb;
    int b = t.getVal(r) - stb;
    
    int res = 0;
    if (minb < 0) {
      res -= minb;
      b -= minb;
      minb = 0;
    }
    assert(b >= 0);
    res += b;

    printf("%d\n", res);
  }
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




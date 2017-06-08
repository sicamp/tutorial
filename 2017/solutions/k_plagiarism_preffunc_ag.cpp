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
#define TASK "plagiarism"

void precalc() {
}

const int maxn = 10010;

int n;
int k;
char s[maxn];

bool read() {
  if (scanf("%s", s) < 1) {
    return false;
  }
  n = strlen(s);
  s[n + 1] = 0;
  scanf("%s", s + n + 1);
  k = strlen(s + n + 1);
  return true;
}

int p[maxn];

void calcp(char *a, int n) {
  p[0] = 0;
  for (int i = 1; i < n; ++i) {
    int x = p[i - 1];
    while (x > 0 && a[x] != a[i]) {
      x = p[x - 1];
    }
    if (a[x] == a[i]) {
      ++x;
    }
    p[i] = x;
  }
}

int cnt[maxn];

void solve() {
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    calcp(s + i, n + k + 1 - i);
    memset(cnt, 0, sizeof(cnt));
    for (int j = n + 1 - i; j < n + k + 1 - i; ++j) {
      if (p[j] > 0) {
        ++cnt[p[j] - 1];
      }
    }
    for (int j = n - i - 1; j > 0; --j) {
      if (p[j] > 0) {
        cnt[p[j] - 1] += cnt[j];
      }
    }
    for (int j = 0; j < n - i; ++j) {
      res += cnt[j];
    }
  }
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




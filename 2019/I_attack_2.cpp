#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const long double one = 1.0;
const long double eps = 1e-10;

pair <int, int> s[maxn];

bool cmp(pair <int, int> a, pair <int, int> b) {
  return (1ll * a.first) * (1ll * b.second) > (1ll * b.first) * (1ll * a.second);
}

long long attack[maxn];

void calc(int n) {
  attack[n] = 0;
  for (int i = n - 1; i >= 0; i--)
    attack[i] = attack[i + 1] + (1ll * s[i].first);
}

int main() {
  int n;
  long long d, p;
  cin >> n >> d >> p;
  for (int i = 0; i < n; i++) {
    cin >> s[i].first >> s[i].second;
  }

  sort(s, s + n, cmp);
  calc(n);

  long double rem = p;
  for (int i = 0; i < n; i++) {
    rem -= ((one * attack[i]) * s[i].second) / (one * d);
    if (rem < 0)
      break;
  }
  if (rem < 0 + eps)
    cout << "YES";
  else
    cout << "NO";
    

  return 0;
}

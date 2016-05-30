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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1002;

int a[MAXN];

int zeros(int a) {
	int res = 0;
	while(a % 10 == 0) {
		a /= 10;
		res++;
	}
	return res;
}

bool zless(int a, int b) {
	int za = zeros(a);
	int zb = zeros(b);
	if (za != zb)
		return za < zb;
	return a < b;
}

int main() {
	freopen("round.in", "r", stdin);
	freopen("round.out", "w", stdout);

	int n;
	scanf("%d", &n);
	FOR(i, n) {
		scanf("%d", &a[i]);
	}
	FOR(i, n - 1) {
		FOR(j, n - i - 1) {
			if (zless(a[j], a[j + 1]))
				swap(a[j], a[j + 1]);
		}
	}
	FOR(i, n) {
		printf("%d\n", a[i]);
	}
	return 0;
}


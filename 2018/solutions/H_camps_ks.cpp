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
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;

const int P = 997;

vector<ll> getHashes(const vector<ll>& a) {
    int n = a.size();
    vector<ll> res(n + 1);
    res[0] = 0;
    for (int i = 0; i < n; ++i) {
        res[i + 1] = res[i] * P + a[i];
    }

    return res;
}

int main() {
    freopen("camps.in", "r", stdin);
    freopen("camps.out", "w", stdout);

    cin.sync_with_stdio(false);
    cin.tie(0);
    int n, k; 
    cin >> n >> k;
    vector<ll> a(n), b(k);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    vector<ll> hashes = getHashes(a);
    ll hashB = *getHashes(b).rbegin();
    ll hash1 = *getHashes(vector<ll>(k, 1)).rbegin();

    ll pToK = 1;
    for (int i = 0; i < k; ++i) {
        pToK *= P;
    }

    for (int i = 0; i <= n - k; ++i) {
        int shift = a[i] - b[0];
        if (hashes[i + k] - hashes[i] * pToK == hashB + hash1 * shift) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
    return 0;
}


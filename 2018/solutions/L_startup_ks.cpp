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

const int INF = 1e9;

struct state {
    int len, first;
    bool operator < (const state other) const {
        if (len != other.len) {
            return len < other.len;
        }

        return first < other.first;
    }
};

vector<string> strings;
vector<vector<int>> overlap;
vector<vector<state>> dp;
vector<vector<int>> prevEnd;

int getOverlapZ(const string& b, const string& a) {
    string s = a + '$' + b;
    vector<int> z(s.length(), 0);
    z[0] = s.length();
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); ++i) {
        if (l <= i && i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < s.length() && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }

    for (int i = a.length() + 2; i < s.length(); ++i) {
        if (i + z[i] == s.length()) {
            return z[i];
        }
    }

    return 0;
}


int main() {
    freopen("startup.in", "r", stdin);
    freopen("startup.out", "w", stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    strings.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    sort(strings.begin(), strings.end());

    overlap.resize(n);
    for (int i = 0; i < n; ++i) {
        overlap[i].resize(n);
        for (int j = 0; j < n; ++j) {
            //overlap[i][j] = getOverlapHash<HashMultiple>(strings[i], strings[j]);
            overlap[i][j] = getOverlapZ(strings[i], strings[j]);
        }
    }
    
    dp.resize(k + 1, vector<state>(n, {INF, 0}));
    prevEnd.resize(k + 1, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        dp[1][i] = {int(strings[i].length()), i};
    }

    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int g = 0; g < n; ++g) {
                int newLength = dp[i][j].len + strings[g].length() - overlap[j][g];
                state newState = {newLength, dp[i][j].first};
                if (newState < dp[i + 1][g]) {
                    dp[i + 1][g] = newState;
                    prevEnd[i + 1][g] = j;
                }
            }
        }
    }

    state ansState = {INF, 0};
    int bestEnd = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[k][i] < ansState) {
            ansState = dp[k][i];
            bestEnd = i;
        }
    }

    vector<int> seq;
    for (int occ = k, end = bestEnd; occ >= 1; end = prevEnd[occ][end], occ--) {
        seq.push_back(end);
    }

    reverse(seq.begin(), seq.end());
    string ans = strings[seq[0]];
    for (int i = 0; i + 1 < seq.size(); ++i) {
        int cur = seq[i];
        int nxt = seq[i + 1];
        ans += strings[nxt].substr(overlap[cur][nxt]);
    }

    assert(ansState.len == ans.length());


    cout << ans << '\n';

    return 0;
}


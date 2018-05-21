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
#include <bitset>

using namespace std;

int main() {
	freopen("stairs.in", "r", stdin);
	freopen("stairs.out", "w", stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> h(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> h[i][j];
        }
    }

    int sumh = 0, cnt = 0;
    vector<vector<int>> tr = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (auto t : tr) {
                int ni = i + t[0];
                int nj = j + t[1];
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                    continue;
                }

                if (h[i][j] > h[ni][nj]) {
                    sumh += h[i][j] - h[ni][nj];
                    cnt++;
                }
            }
        }
    }

    cout << sumh << ' ' << cnt << '\n';
    return 0;
}


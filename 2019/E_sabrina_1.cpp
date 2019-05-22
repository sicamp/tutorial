#include <stdio.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#define ll long long



int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // _DEBUG
    int x = 0, y = 0;


    string s, t;
    cin >> s;
    t = s;
    int n = s.size();
    vector<bool>A(30);
    for (int i = 0; i < n; i++) {
        if (s[i] - 'a' < 0) {
            s[i] = (s[i] - 'A') + 'a';
        }
        A[s[i] - 'a'] = 1;
    }

    for (int i = 0; i < 30; i++) {
        if (A[i]) {
            x = i;
            break;
        }
    }

    for (int i = 29; i > 0; i--) {
        if (A[i]) {
            y = i;
            break;
        }
    }
    vector<pair<int, int>>C;
    for (int i = 0; i < n; i++) {
        if (s[i] - 'a' == x)
            C.push_back({ i, 0 });
        if (s[i] - 'a' == y)
            C.push_back({ i, 1 });
    }
    int j = 0, k = 0, ans = 1e9;

    for (int i = 0; i < C.size() - 1; i++) {
        if (C[i].second != C[i + 1].second) {
            if (abs(C[i].first - C[i + 1].first) <= ans) {
                ans = abs(C[i].first - C[i + 1].first);
                j = C[i].first;
                k = C[i + 1].first;
            }
        }
    }
    if (j > k)
        swap(j, k);
    for (int i = j; i <= k; i++)
        cout << t[i];

    return 0;
}

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

string first[200];

int main() {
    freopen("first.in", "r", stdin);
    freopen("first.out", "w", stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        char c = name[0];
        if (first[c].length() == 0) {
            first[c] = name;
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        if (first[c].length() > 0) {
            cout << first[c] << '\n';
        }
    }
    return 0;
}


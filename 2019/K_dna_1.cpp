#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const long long hashPoint = 997;

struct Hasher {
    vector<long long> h;
    vector<long long> p;
    Hasher(const string& s) {
        int n = s.length();
        h.resize(n + 1);
        p.resize(n + 1);
        p[0] = 1;

        for (int i = 0; i < n; ++i) {
            h[i + 1] = h[i] * hashPoint + s[i];
            p[i + 1] = p[i] * hashPoint;
        }
    }

    long long get(int l, int r) {
        return h[r] - h[l] * p[r - l];
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    string s, t;
    cin >> s >> t;

    set<long long> substrings;
    for (int i = 0; i < t.length(); ++i) {
        long long h = 0;
        for (int j = i; j < t.length(); ++j) {
            h = h * hashPoint + t[j];
            substrings.insert(h);
        }
    }

    int ansl = 0, ansr = s.length() + 1;
    Hasher h(s);
    int r = 0;
    for (int i = 0; i < s.length(); ++i) {
        r = max(i, r);
        while (r < s.length() && substrings.count(h.get(i, r + 1)) > 0) {
            r++;
        }
        if (r < s.length() && (ansr - ansl > r + 1 - i)) {
            ansl = i;
            ansr = r + 1;
        }
    }

    if (ansr == s.length() + 1) {
        cout << "NONE\n";
    } else {
        cout << s.substr(ansl, ansr - ansl) << '\n';
    }

    return 0;
}

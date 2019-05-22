#include <bits/stdc++.h>

using namespace std;

vector <long long> ans;
vector <int> s(32,0);

int main()
{
    long long i, k, n, m, ch, kol = 0, ch2;
    cin >> n >> m;
    ch2 = n;
    for (i = 31; i > 31 - m; i--)
        s[i] = 1;
    ch = 0;
    do
    {
        ch = 0;
        k = 1;
        for (i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == 1)
                ch += k;
            k*=2;
        }
        if (ch > ch2)
            break;
        kol++;
        ans.push_back(ch);
    }while(    next_permutation(s.begin(), s.end()));
    cout << ans.size() << " ";
    n = ans.size();
    if (n > 1000)
        n = 1000;
    for (i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}

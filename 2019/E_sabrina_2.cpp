#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string s;
char B[200003][2];
int A[200003][2],mx,mn, j;
int main()
{
    cin >> s;
    string s1 = s;
    s[0] = ('A' <= s[0] && s[0] <= 'Z'? s[0] : s[0] - 'a' + 'A');
    B[0][0] = s[0];
    B[0][1] = s[0];
    A[0][0] = 0;
    A[0][1] = 0;
    for(int i =1; i < s.size(); i++)
    {
        s[i] = ('A' <= s[i] && s[i] <= 'Z'? s[i] : s[i] - 'a' + 'A');
        if(s[i] <= B[i - 1][0])
        {
            B[i][0] = s[i];
            A[i][0] = i;
        }
        else
        {
            B[i][0] = B[i - 1][0];
            A[i][0] = A[i - 1][0];
        }
        if(s[i] >= B[i - 1][1])
        {
            B[i][1] = s[i];
            A[i][1] = i;
        }
        else
        {
            B[i][1] = B[i - 1][1];
            A[i][1] = A[i - 1][1];
        }
    }
    mx = 0;
    mn = s.size();
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if((abs(s[i] - B[i][0]) > mx) || (abs(s[i] - B[i][0]) == mx) && (i - A[i][0] + 1 < mn))
        {
            mx = abs(s[i] - B[i][0]);
            mn = i - A[i][0] + 1;
            j = A[i][0];

        }
        if((abs(s[i] - B[i][1]) > mx) || (abs(s[i] - B[i][1]) == mx) && (i - A[i][1] + 1 < mn))
        {
            mx = abs(s[i] - B[i][1]);
            mn = i - A[i][1] + 1;
            j = A[i][1];
        }
    }
    cout << s1.substr(j,mn);
    return 0;
}


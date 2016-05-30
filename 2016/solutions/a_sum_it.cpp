#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main()
{
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    int n, d, mi = 100100, ma = -100100;

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> d;
        if(i % 2 && mi > d) mi = d;
        if(i % 2 == 0 && ma < d) ma = d;
    }

    cout << mi + ma;

    return 0;
}


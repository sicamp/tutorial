#include<iostream>
using namespace std;

const int maxN = 1000 + 10;

char s[maxN][maxN];

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    int n, v;
    scanf("%d%d", &n, &v);
    v--;
    for(int i = 0; i < n; i++) 
        scanf("%s", s[i]);

    int res = 0;
    for(int a = 0; a < n; a++)
        for(int b = 0; b < n; b++)
            if(s[v][a] == '1' && s[a][b] == '1' && s[b][v] == '1') {
                res++;
            }

    if(res != 0)
        printf("3 %d\n", res);
    else
        printf("-1\n");
    return 0;
}

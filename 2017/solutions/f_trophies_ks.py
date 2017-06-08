import sys
sys.setrecursionlimit(5 * 10**5)
calls = 0
ans = -1
INF = 2 * 10**9 + 1
def dfs(v, par = -1):
    global calls, ans, INF
    calls += 1
    mx = -INF
    for u in e[v]:
        if u == par:
            continue
        cmax = dfs(u, v)
        ans = max(ans, mx + cmax)
        mx = max(cmax, mx)
    mx = max(mx, c[v])
    return mx

fin = open("trophies.in")
fout = open("trophies.out", "w")
n = int(fin.readline().strip())
assert(1 <= n <= 200000)
c = list(map(int, fin.readline().strip().split()))
for w in c:
    assert(0 <= w <= 10**9)
e = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = map(int, fin.readline().strip().split())
    assert(1 <= u <= n)
    assert(1 <= v <= n)
    assert(u != v)
    u -= 1
    v -= 1
    e[u].append(v)
    e[v].append(u)
dfs(0)
assert(calls == n)
fout.write(str(ans) + '\n')
fout.close()




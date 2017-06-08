MOD = 10**9 + 7

fin = open("jokes.in")
fout = open("jokes.out", "w")

n, k, m = map(int, fin.readline().strip().split())
assert(1 <= n <= 20)
assert(1 <= k <= 26)
assert(0 <= m <= k**2)


scnt = 0
f = [[False] * k for i in range(k)]
ss = set()
for s in fin.readlines():
    s = s.strip()
    ss.add(s)
    assert(len(s) == 2)
    si = [i - ord('a') for i in map(ord, list(s))]
    f[si[0]][si[1]] = True
    scnt += 1
assert(scnt == m)
assert(len(ss) == m)

dp = [[[0, 0] for i in range(k)] for g in range(n + 1)]
for i in range(k):
    dp[1][i][0] = 1
for l in range(1, n):
    for i in range(k):
        for j in range(k):
            if f[i][j]:
                dp[l + 1][j][1] += dp[l][i][0]
                dp[l + 1][j][1] %= MOD
            else:
                for x in range(2):
                    dp[l + 1][j][x] += dp[l][i][x]
                    dp[l + 1][j][x] %= MOD
ans = 0
for i in range(k):
    for x in range(2):
        ans += dp[n][i][x]
fout.write(str(ans % MOD) + '\n')
fout.close()

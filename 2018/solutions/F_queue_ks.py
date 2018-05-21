import sys

sys.stdin = open("queue.in", "r")
sys.stdout = open("queue.out", "w")

def main():
    n, k = map(int, input().split())
    m = n + k
    p = list(map(int, input().split()))
    d = int(input())

    dp = [[10**9] * m for _ in range(k)]
    prev = [[-1] * m for _ in range(k)]
    dp[0] = p

    for i in range(0, k - 1):
        best = dp[i][i]
        bestPrev = i
        for j in range(i + 1, m):
            dp[i + 1][j] = best + p[j]
            prev[i + 1][j] = bestPrev
            best += d
            if dp[i][j] < best:
                best = dp[i][j]
                bestPrev = j

    best = 10**9
    for i in range(m):
        if dp[k - 1][i] < best:
            best = dp[k - 1][i]
            bestPos = i

    i = k - 1
    j = bestPos
    ans = []
    while i >= 0:
        ans.append(j + 1)
        j = prev[i][j]
        i -= 1

    print(best)
    print(*reversed(ans))

main()

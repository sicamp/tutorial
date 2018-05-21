import sys

sys.stdin = open("baloons.in", "r")
sys.stdout = open("baloons.out", "w")

N = 2 ** 16
ans = [-1] * N
for i in range(N):
    res = i ^ (2 * i)
    if res < N:
        if ans[res] == -1:
            ans[res] = i

n = int(input())
q = list(map(int, input().split()))
res = ""
for x in q:
    res += str(ans[x]) + ' '

print(res)


def abs(x):
    if x < 0:
        return -x
    return x

n, m = map(int, input().split())
at = []
ax = []
ay = []
bt = []
bx = []
by = []

for i in range(n):
    t, x, y = map(int, input().split())
    at.append(t)
    ax.append(x)
    ay.append(y)


for i in range(m):
    t, x, y = map(int, input().split())
    bt.append(t)
    bx.append(x)
    by.append(y)

best = 10**9
for i in range(m):
    dist = 0
    for j in range(n):
        length = abs(ax[j] - bx[i]) + abs(ay[j] - by[i])
        if at[j] != bt[i]:
            length *= 2
        dist += length
    if dist < best:
        best = dist

print(best)







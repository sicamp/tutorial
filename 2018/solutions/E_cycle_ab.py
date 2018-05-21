f = open("cycle.in", "r") 
n, v = map(int, f.readline().split())
v = v - 1
s = [f.readline() for i in range(0, n)]
res = 0
for a in range(0, n):
    for b in range(0, n):
        if (s[v][a] == s[a][b] == s[b][v] == '1'):
            res = res + 1

f = open("cycle.out", "w")
if res == 0:
    print("-1\n", file=f)
else:
    print("3 " + str(res) + "\n", file=f)

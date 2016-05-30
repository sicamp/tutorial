from fractions import gcd

f = open("chemistry.in")
g = open("chemistry.out", "w")

n, k = map(int, f.readline().strip().split())
s = f.readline().strip()
t = f.readline().strip()
k2 = n - k
m = 2 * k2 * k // gcd(k2, k)
st = s
for i in range(m):
    if s == t:
        g.write(str(i) + '\n')
        break
    if i % 2 == 0:
        s = s[1:k] + s[0] + s[k:]
    else:
        s = s[0:k] + s[n - 1] + s[k:n - 1]
else:
    g.write('-1\n')
g.close()

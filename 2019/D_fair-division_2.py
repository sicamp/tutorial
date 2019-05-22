def gcd(a, b):
    if a > b:
        a, b = b, a
    if a == 0:
        return b
    return gcd(b % a, a)


n, m = map(int, input().split())
c = input().split()
p = input().split()
ans = 10 ** 10
for i in range(m):
    c[i] = int(c[i])
    p[i] = int(p[i])
    ans = min(ans, p[i] * n // gcd(n, c[i]))
print(ans)


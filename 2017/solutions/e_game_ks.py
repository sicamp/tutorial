MAXC = 10**9

def divs(a):
    p = 1
    d = [] 
    while p * p <= a:
        if a % p == 0:
            d.append(p)
            if p * p < a:
                d.append(a / p)
        p += 1
    return d

fin = open("game.in")
fout = open("game.out", "w")
a, b = map(int, fin.read().split())
assert(1 <= a <= MAXC)
assert(1 <= b <= MAXC)
da = divs(a)
db = divs(b)
dab = 0
for x in da:
    if b % x == 0:
        dab += 1
print(len(da) - dab, len(db) - dab, dab, file=fout)





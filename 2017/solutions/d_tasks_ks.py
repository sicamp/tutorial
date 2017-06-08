fin = open("tasks.in")
fout = open("tasks.out", "w")
n = int(fin.readline().strip())
t = [(tuple(sorted(s.strip())), s.strip()) for s in fin.readlines()]
assert(n == len(t))
assert(n == len(set([p[0] for p in t])))
for p in sorted(t):
    print(p[1], file=fout)

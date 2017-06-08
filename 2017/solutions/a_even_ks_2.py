def aprint(a):
    fout.write(str(len(a)) + '\n')
    for x in a:
        fout.write(str(x) + ' ')
    fout.write('\n')

fin = open("even.in")
fout = open("even.out", "w")

n = int(fin.readline().strip())
a = list(map(int, fin.readline().strip().split()))
even = []
odd = []
for x in a:
    if x % 2 == 0:
        even.append(x)
    else:
        odd.append(x)
aprint(even)
aprint(odd)
fout.close()

        




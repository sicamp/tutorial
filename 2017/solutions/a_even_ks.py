fin = open("even.in")
fout = open("even.out", "w")

n = int(fin.readline().strip())
a = list(map(int, fin.readline().strip().split()))
even = 0
odd = 0
for x in a:
    if x % 2 == 0:
        even += 1
    else:
        odd += 1
fout.write(str(even) + '\n')
for x in a:
    if x % 2 == 0:
        fout.write(str(x) + ' ')
fout.write('\n')
fout.write(str(odd) + '\n')
for x in a:
    if x % 2 == 1:
        fout.write(str(x) + ' ')
fout.write('\n')
fout.close()

        




def dsum(s):
    res = 0
    for d in s:
        res += ord(d) - ord('0')
    return res

fin = open("nine.in")
fout = open("nine.out", "w")
a = fin.readline().strip()
b = fin.readline().strip()
if dsum(a) * dsum(b) % 9 == 0:
    fout.write("Yes\n")
else:
    fout.write("No\n")

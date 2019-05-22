s = input()
assert(1 <= len(s) <= 100000)

minl = 10**9
maxl = 0
minpos = -1
maxpos = -1
bestdif = -1
bestlen = 0
for i in range(len(s) - 1, -1, -1):
    l = ord(s[i])
    assert((ord('a') <= l <= ord('z')) or (ord('A') <= l <= ord('Z')))
    if ord('a') <= l <= ord('z'):
        l -= ord('a')
        l += ord('A')
    if l < minl:
        minl = l
    if l == minl:
        minpos = i

    if l > maxl:
        maxl = l
    if l == maxl:
        maxpos = i

    if l - minl > bestdif or (l - minl == bestdif and minpos - i + 1 < bestlen):
        bestdif = l - minl
        bestl = i
        bestr = minpos
        bestlen = minpos - i + 1

    if maxl - l > bestdif or (maxl - l == bestdif and maxpos - i + 1 < bestlen):
        bestdif = maxl - l
        bestl = i
        bestr = maxpos
        bestlen = maxpos - i + 1
print(s[bestl:bestr + 1])





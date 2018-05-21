import sys

sys.stdin = open("stairs.in", "r")
sys.stdout = open("stairs.out", "w")

n, m = map(int, input().split(" "))

a = []
for i in range(n):
	a.append(list(map(int, input().split(" "))))

s, cnt = 0, 0

for i in range(n):
	for j in range(m-1):
		delta = abs(a[i][j] - a[i][j+1])
		s += delta
		if delta > 0:
			cnt += 1

for i in range(n-1):
	for j in range(m):
		delta = abs(a[i][j] - a[i+1][j])
		s += delta
		if delta > 0:
			cnt += 1

print(s, cnt)

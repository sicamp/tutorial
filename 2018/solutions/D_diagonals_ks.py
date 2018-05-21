import sys

sys.stdin = open("diagonals.in", "r")
sys.stdout = open("diagonals.out", "w")

def main():
  n, m = map(int, input().split())

  a = []
  for i in range(n):
    a.append(list(map(int, input().split())))

  b = []
  for i in range(n + m - 1):
    dlen = 0
    dsum = 0
    dmax = 0

    x = i if i < n else n - 1
    y = 0 if i < n else i - (n - 1)

    while x >= 0 and y < m:
      dlen += 1
      dsum += a[x][y]
      dmax = max(dmax, a[x][y])
      x -= 1
      y += 1

    b.append((dlen, dsum, dmax, i + 1))

  for i in range(len(b) - 1):
    for j in range(len(b) - i - 1):
      if b[j] > b[j + 1]:
        b[j], b[j + 1] = b[j + 1], b[j]

  ans = []
  for i in range(n + m - 1):
    ans.append(b[i][3])

  print(*ans)
main()

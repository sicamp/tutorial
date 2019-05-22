def main():
  n = int(input())
  a = []
  for i in range(501):
    a.append([0] * 501)
  for i in range(n):
    x, y = map(int, input().split())
    a[x][y] += 1
  mx = 0
  for i in range(501):
    mx = max(mx, max(a[i]))
  print(mx)
main()
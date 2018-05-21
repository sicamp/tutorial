import sys

sys.stdin = open("chessboard.in", "r")
sys.stdout = open("chessboard.out", "w")

sys.setrecursionlimit(10**7)

ts = ((0, 1), (1, 0), (0, -1), (-1, 0))
def dfs(x, y):
    global n, m, board, used, ts
    used[x][y] = True
    for t in ts:
        nx = x + t[0]
        ny = y + t[1]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if used[nx][ny] or board[nx][ny] == board[x][y]:
            continue
        dfs(nx, ny)

def main():
    global n, m, board, used
    n, m = map(int, input().split())
    board = []
    for i in range(n):
        board.append(input().strip())

    ans = 0
    used = [[False] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if not used[i][j]:
                ans += 1
                dfs(i, j)

    print(ans)

main()

from queue import Queue

dx = [-1, -1, -2, -2, 1, 1, 2, 2]
dy = [2, -2, 1, -1, 2, -2, 1, -1]


def horse(n, sx, sy, ex, ey):
    vis = [[False for i in range(0, n)] for j in range(0, n)]
    vis[sx][sy] = True

    def check(x, y, dx, dy):
        if vis[x + dx][y + dy]:
            return False

        if x + dx < 0 or x + dx >= n:
            return False

        if y + dy < 0 or y + dy >= n:
            return False

        return True

    q = Queue()
    t = 0
    q.put((t, sx, sy))
    while not q.empty():
        t, x, y = q.get()
        if x == ex and y == ey:
            return t

        for nx, ny in zip(dx, dy):
            if check(x, y, nx, ny):
                q.put((t + 1, x + nx, y + ny))
                vis[x + nx][y + ny] = True

    return -1

print(horse(200, 1, 1, 2, 1))
print(horse(200, 1, 5, 5, 1))

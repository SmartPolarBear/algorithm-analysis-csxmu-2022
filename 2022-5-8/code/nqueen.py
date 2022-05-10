from queue import Queue


def check(pos, k, i):
    if pos[k] >= 0:
        return False

    for j in range(0, k):
        if pos[j] == i:
            return False

        if i - pos[j] == j - k:
            return False

        if i - pos[j] == k - j:
            return False

    return True


def n_queen(n):
    k, pos = 0, [-1 for i in range(0, n)]
    ans = 0
    q = Queue()
    q.put((k, pos))
    while not q.empty():
        k, pos = q.get()
        if k == n:
            print(pos)
            ans += 1
            continue

        for i in range(0, n):
            if check(pos, k, i):
                q.put((k + 1, [i if r == k else pos[r] for r in range(0, n)]))
    return ans


print(n_queen(8))

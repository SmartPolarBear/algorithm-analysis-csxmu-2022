from queue import PriorityQueue

c = [[3, 5, 2, 4], [6, 7, 5, 3], [3, 7, 4, 5], [8, 5, 4, 6]]


def get_min():
    mins = []
    for i in range(0, 4):
        minval = 0x7fffffff
        for j in range(0, 4):
            minval = min([minval, c[j][i]])
        mins.append(minval)
    return mins


def assign():
    mins = get_min()

    def b():
        ret = cur
        for i in range(step, 4):
            if not vis[i]:
                ret += mins[i]
        return ret

    ans = 0x7fffffff
    cur, step, vis = 0, 0, [False for _ in range(0, 4)]
    q = PriorityQueue()
    while step < 4:
        for i in range(0, 4):
            new_cost = cur + c[i][step]

            if vis[i] or new_cost > ans:
                continue

            if step >= 3:
                ans = min([ans, new_cost])

            vis[i] = True
            q.put([b(), (new_cost, step + 1, vis)])
            vis[i] = False

        _, (cur, step, vis) = q.get()
    return ans


print(assign())

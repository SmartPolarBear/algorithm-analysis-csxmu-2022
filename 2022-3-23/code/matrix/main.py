p = list([5, 10, 3, 12, 5, 50, 6])
N = 6

m = list([list([0x7fffffff for i in range(0, N + 1)]) for j in range(0, N + 1)])
s = list([list([0x7fffffff for i in range(0, N + 1)]) for j in range(0, N + 1)])


def pretty_print(i, j):
    if i == j:
        print('A{}'.format(i), end=' ')
    else:
        print("(", end=' ')
        pretty_print(i, s[i][j])
        pretty_print(s[i][j] + 1, j)
        print(")", end=' ')


for i in range(1, N + 1):
    m[i][i] = 0

for i in range(N, 0, -1):
    for j in range(i, N + 1):
        if i == j:
            m[i][j] = 0
        else:
            for k in range(i, j):
                val = m[i][k] + m[k + 1][j] + p[i - 1] * p[j] * p[k]
                if m[i][j] > val:
                    m[i][j] = val
                    s[i][j] = k

for i in range(1, N + 1):
    for j in range(1, N + 1):
        print("inf" if m[i][j] == 0x7fffffff else m[i][j], end=' ' if j != N else '\n')

for i in range(1, N + 1):
    for j in range(1, N + 1):
        print("None" if s[i][j] == 0x7fffffff else s[i][j], end=' ' if j != N else '\n')

pretty_print(1, N)

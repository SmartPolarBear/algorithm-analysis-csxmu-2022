n = int(input())

print(sum(1 for i in filter(lambda x: n % x == 0, range(1, n + 1))))

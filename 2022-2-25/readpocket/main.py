import random
from typing import Final, List

scheme_diff: List[int] = list({1.65, 1.67, 16.79, 1.77, 17.79, 1.87, 18.79, 1.98,
                               5.19, 0.65, 6.59, 6.65, 0.07, 0.87, 8.79, 8.87, 0.98, 9.89, 9.98})

m, n = input("m and n:").split()

n = int(n)
m = float(m) - n * 0.01

result = list([0.01 for i in range(0, n)])

for i in range(0, n):
    amount = scheme_diff[random.randrange(0, len(scheme_diff))]
    if m - amount == 0:
        result[i] += amount
        break
    elif m - amount < 0:
        result[i] += m
        break
    else:
        m -= amount
        result[i] += amount

result = list([round(r, 2) for r in result])

print(result)

def gcd(a, b):
    return b if a % b == 0 else gcd(b, a % b)


a, b = map(int, input().split())
g = gcd(a, b)

print(g, a * b // g, sep='\n')

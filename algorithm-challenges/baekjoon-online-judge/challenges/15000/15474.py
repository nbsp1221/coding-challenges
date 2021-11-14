import math

n, a, b, c, d = map(int, input().split())
r1 = math.ceil(n / a) * b
r2 = math.ceil(n / c) * d

print(r1 if r1 < r2 else r2)

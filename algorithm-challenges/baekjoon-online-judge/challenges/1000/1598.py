import math

a, b = map(int, input().split())
print(abs(math.ceil(a / 4) - math.ceil(b / 4)) + abs((a - 1) % 4 - (b - 1) % 4))

import math

a, b, c = map(int, input().split())
week = c // (a * 7 + b)
day = math.ceil((c - week * (a * 7 + b)) / a)

print(min((week + 1) * 7, week * 7 + day))

n = int(input())
k = int(input())

print(min(n, k + 60) * 1500 + (n - min(n, k + 60)) * 3000)

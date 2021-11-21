arr = list(map(int, input().split()))
answer = sum([max(arr) - x for x in arr])

print(answer)

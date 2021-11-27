value = int(input())
answer = value * 0.01 + 25

if answer < 100:
    answer = 100

if answer > 2000:
    answer = 2000

print('{:.2f}'.format(answer))

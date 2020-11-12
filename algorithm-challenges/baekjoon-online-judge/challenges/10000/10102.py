n = int(input())
checker = 0

for vote in input():
    if vote == 'A':
        checker += 1
    else:
        checker -= 1

if checker > 0:
    print('A')
elif checker < 0:
    print('B')
else:
    print('Tie')

left, right = map(int, input().split())

if left == 0 and right == 0:
    print('Not a moose')
elif left == right:
    print('Even', left * 2)
else:
    print('Odd', left * 2 if left > right else right * 2)

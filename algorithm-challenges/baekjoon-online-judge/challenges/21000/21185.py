n = int(input())
value = n * (n - 1) // 2

if n % 2 == 0:
    print('Even' if value % 2 == 0 else 'Odd')
else:
    print('Either')

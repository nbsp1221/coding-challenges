t = int(input())

while t > 0:
    datas = input().split()
    value = float(datas[0])

    for op in datas[1:]:
        if op == '@': value *= 3
        elif op == '%': value += 5
        else: value -= 7

    print(format(value, '.2f'))
    t -= 1

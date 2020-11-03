value = input()

if value[:2] == '0x':
    print(int(value, 16))
elif value[0] == '0':
    print(int(value, 8))
else:
    print(value)

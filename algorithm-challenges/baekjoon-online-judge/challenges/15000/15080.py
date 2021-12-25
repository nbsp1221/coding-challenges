first_time = list(map(int, input().split(' : ')))
first_value = first_time[0] * 3600 + first_time[1] * 60 + first_time[2]

second_time = list(map(int, input().split(' : ')))
second_value = second_time[0] * 3600 + second_time[1] * 60 + second_time[2]

if first_value <= second_value:
    print(second_value - first_value)
else:
    print(86400 - first_value + second_value)

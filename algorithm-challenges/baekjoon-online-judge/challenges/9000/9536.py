t = int(input())

while t > 0:
    sounds = input().split()

    while True:
        sound_info = input()
        splitted = sound_info.split()

        if sound_info == 'what does the fox say?':
            break

        sounds = list(filter(lambda x: x != splitted[2], sounds))

    print(' '.join(sounds))
    t -= 1

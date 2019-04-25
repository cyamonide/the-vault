
m = input()
r = int(input())

s = 0
spamming = False
for i in m:
    if i == 'S':
        s += 1
        if s >= r:
            print("Spamming")
            spamming = True
            break
    if i == 'R':
        s = 0

if not spamming:
    print("All good")
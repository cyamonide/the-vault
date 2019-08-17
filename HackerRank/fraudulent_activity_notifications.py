#!/bin/python3


def median(aux, d):
    counter = 0
    if d % 2:
        for i, val in enumerate(aux):
            counter += val
            if counter >= (d//2 + 1):
                return i
    else:
        val1 = 0
        val2 = 0
        for i, val in enumerate(aux):
            counter += val
            if val1 == 0 and counter >= d/2:
                val1 = i
            if val2 == 0 and counter >= d/2+1:
                val2 = i
            if val1 and val2:
                return (val1 + val2) / 2


n, d = map(int, input().split())
e = list(map(int, input().split()))

notifs = 0

aux = [0 for _ in range(201)]

# initialize aux array
for i in range(d):
    aux[e[i]] += 1

# traverse remaining to determine notifs
for i, val in enumerate(e):
    if i < d:
        continue
    if val >= 2*median(aux, d):
        notifs += 1
    aux[e[i-d]] -= 1
    aux[val] += 1

print(notifs)

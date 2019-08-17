#!/bin/python3

def sol():
    s = input()
    last = ' '
    newLen = 0
    for c in s:
        if c != last:
            newLen += 1
            last = c

    print(len(s) - newLen)


q = int(input())

for _ in range(q):
    sol()
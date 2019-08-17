#!/bin/python3

def comp(a, i, b, j):
    n = len(a)
    m = len(b)
    while i < n and j < m:
        if a[i] == b[j]:
            i += 1
            j += 1
            continue
        return a[i] < b[j]
    return i == n

def sol():
    a = input()
    b = input()
    i = 0
    j = 0
    outstr = ''

    swap = False

    n = len(a)
    m = len(b)
    while i < n and j < m:
        # construct output string
        if a[i] < b[j]:
            outstr += a[i]
            i += 1
        elif a[i] > b[j]:
            outstr += b[j]
            j += 1
        else: # a[i] == b[j]
            # check if next letter is also equal
            if i+1 < n and j+1 < m and a[i+1] == b[j+1] and a[i] == a[i+1]:
                outstr += a[i] + b[j]
                i += 1
                j += 1
            else:
                if comp(a, i, b, j):
                    outstr += a[i]
                    i += 1
                else:
                    outstr += b[j]
                    j += 1
    outstr += a[i:] + b[j:]
    print(outstr)


t = int(input())

for _ in range(t):
    sol()
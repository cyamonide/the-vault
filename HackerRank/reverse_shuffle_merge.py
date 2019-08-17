#!/bin/python3

def lex_min(d):
    for c in "abcdefghijklmnopqrstuvwxyz":
        if d[c] > 0:
            return c
    return '$'

def sol():
    s = input()
    d = {}
    for char in "abcdefghijklmnopqrstuvwxyz":
        d[char] = 0
    for char in s:
        d[char] += 1

    origCount = {}
    shufCount = {}
    for char in "abcdefghijklmnopqrstuvwxyz":
        origCount[char] = d[char] // 2
        shufCount[char] = d[char] // 2

    s = ''.join(reversed(s))

    orig = ''

    for c in s:
        if origCount[c] == 0:
            shufCount[c] -= 1
        elif shufCount[c] == 0:
            origCount[c] -= 1
            orig += c
        elif c == lex_min(origCount):
            origCount[c] -= 1
            orig += c
        else:
            shufCount[c] -= 1

    print(orig)

sol()
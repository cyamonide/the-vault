#!/bin/python3

import math

q = int(input())

def ncr(n, r):
    return int(math.factorial(n) / (math.factorial(r) * math.factorial(n-r)))

def sol():
    s = input()

    pairs = 0

    for ss in range(1, len(s) + 1):
        d = {}
        for i in range(len(s) - ss + 1):
            substr = ''.join(sorted(s[i:i+ss]))
            d[substr] = d.get(substr, 0) + 1

        for k in d:
            if d[k] >= 2:
                pairs += ncr(d[k], 2)

    print(pairs)


for _ in range(q):
    sol()
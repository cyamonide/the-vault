#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the luckBalance function below.
def luckBalance(k, contests):
    balance = 0
    importants = []
    for l, t in contests:
        if t == 0:
            balance += l
        else:
            importants.append(l)

    importants.sort(reverse=True)
    for i in range(len(importants)):
        if i < k:
            balance += importants[i]
        else:
            balance -= importants[i]

    return balance

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    contests = []

    for _ in range(n):
        contests.append(list(map(int, input().rstrip().split())))

    result = luckBalance(k, contests)

    fptr.write(str(result) + '\n')

    fptr.close()

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the getMinimumCost function below.
def getMinimumCost(k, c):
    f = [0 for _ in range(k)]
    totalCost = 0
    c_s = sorted(c, reverse=True)
    for i, cost in enumerate(c_s):
        totalCost += (f[i % k] + 1) * cost
        f[i%k] += 1

    return totalCost
 
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    c = list(map(int, input().rstrip().split()))

    minimumCost = getMinimumCost(k, c)

    fptr.write(str(minimumCost) + '\n')

    fptr.close()

"""
whiteboarding

k = 3 friends, buying
n = 4 flowers, costing
c = [1, 2, 3, 4]

most expensive flowers should be bought earliest on
fill up friends as equally as possible
- note that only the previous NUMBER of flowers bought
   influences the multiplier
- so, the multiplier doesn't depend on how EXPENSIVE the
   previous flowers were
"""
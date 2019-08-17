#!/bin/python3

import math
import os
import random
import re
import sys

def ncr(n, r):
    return int(math.factorial(n) / (math.factorial(r) * math.factorial(n-r)))

# Complete the countTriplets function below.
def countTriplets(arr, r):
    if r == 1:
        # special case
        d = {}
        for val in arr:
            d[val] = d.get(val, 0) + 1
        triplets = 0
        for k in d:
            l = d[k]
            if l >= 3:
                triplets += ncr(l, 3)

        return triplets

    triplets = 0
    d = {}
    d_pairs = {}
    rev = reversed(arr)
    for val in rev:
        d[val] = d.get(val, 0) + 1 # increment counter
        d_pairs[(val, val*r)] = d_pairs.get((val, val*r), 0) + d.get(val*r, 0)
        triplets += d_pairs.get((val*r, val*r*r), 0)

    return triplets


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nr = input().rstrip().split()

    n = int(nr[0])

    r = int(nr[1])

    arr = list(map(int, input().rstrip().split()))

    ans = countTriplets(arr, r)

    fptr.write(str(ans) + '\n')

    fptr.close()

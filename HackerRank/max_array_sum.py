#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxSubsetSum function below.
def maxSubsetSum(arr):
    arr = [0] + arr
    if len(arr) == 1:
        return arr[0]
    elif len(arr) == 2:
        return max(arr[0], arr[1])

    # initialize max_until array
    f = [arr[0], max(arr[0], arr[1])]
    incl = [True, arr[1] > arr[0]]

    for i in range(2, len(arr)):
        a, b = f[-2:]
        c = arr[i]
        b_incl = incl[-1]
        c_incl = c > 0
        new_max = 0

        if b_incl:
            new_max = max(a, a+c)
            if b > new_max:
                new_max = b
                c_incl = False
        else:
            new_max = max(a, a+c, b, b+c)

        f.append(new_max)
        incl.append(c_incl)

    return f[-1]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = maxSubsetSum(arr)

    fptr.write(str(res) + '\n')

    fptr.close()


"""
let f(n) be the maximum sum up until element n

[a, b] => max sum is the larger of a and b
keep an "incl" array

[a, b, c]
f(a) is a
f(b) is max(a, b)
f(c) is
    max(f(b), f(b)+c, f(a), f(a) + c) if b wasn't incl in f(b)
    max(f(a), f(a)+c) if b was incl in f(b)
    if c is positive (not non-negative) then c will be incl in f(c)
"""
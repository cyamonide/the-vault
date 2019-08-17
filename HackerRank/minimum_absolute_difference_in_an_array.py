#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumAbsoluteDifference function below.
def minimumAbsoluteDifference(arr):
    a = sorted(arr)
    minAbsDiff = abs(a[0] - a[1])
    for i in range(1, len(arr)):
        minAbsDiff = min(minAbsDiff, abs(a[i] - a[i-1]))

    return minAbsDiff

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = minimumAbsoluteDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()

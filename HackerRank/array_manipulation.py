#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the arrayManipulation function below.


def arrayManipulation(n, queries):
    # goddamn this solution is dope
    arr = [0 for _ in range(n)]
    for i, query in enumerate(queries):
        a, b, k = query
        a -= 1
        b -= 1
        arr[a] += k
        if b < (n-1):
            arr[b+1] -= k

    # traverse arr
    maxSum = 0
    thisSum = 0
    for i in arr:
        thisSum += i
        maxSum = max(maxSum, thisSum)

    return maxSum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)

    fptr.write(str(result) + '\n')

    fptr.close()

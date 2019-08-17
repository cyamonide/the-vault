#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the freqQuery function below.
def freqQuery(queries):
    output = []
    d_vals = {}
    d_counts = {}
    for op, val in queries:
        if op == 1:
            d_vals[val] = d_vals.get(val, 0) + 1
            count = d_vals[val]
            d_counts[count] = d_counts.get(count, 0) + 1
            d_counts[count - 1] = d_counts.get(count - 1, 0) - 1
        elif op == 2:
            if d_vals.get(val, 0):
                # val exists in our data structure
                d_vals[val] = d_vals[val] - 1 # decrement val count
                count = d_vals[val]
                # remove val from old count
                d_counts[count + 1] = d_counts[count + 1] - 1
                # add val to new count
                d_counts[count] = d_counts.get(count, 0) + 1
        elif op == 3:
            if d_counts.get(val, 0):
                output.append(1)
            else:
                output.append(0)

    return output

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    ans = freqQuery(queries)

    fptr.write('\n'.join(map(str, ans)))
    fptr.write('\n')

    fptr.close()

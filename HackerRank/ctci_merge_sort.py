#!/bin/python3

import math
import os
import random
import re
import sys

def merge_sort_with_swaps(arr, swaps):
    n = len(arr)
    if n <= 1:
        return arr, swaps

    # larger cases
    p1, s1 = merge_sort_with_swaps(arr[:n//2], 0)
    p2, s2 = merge_sort_with_swaps(arr[n//2:], 0)

    more_swaps = 0
    i1 = 0
    i2 = 0
    n1 = len(p1)
    n2 = len(p2)

    # count inversions
    while i1 < n1 or i2 < n2:
        if i1 < n1 and i2 < n2:
            if p1[i1] <= p2[i2]:
                i1 += 1
            else:
                more_swaps += n1 - i1
                i2 += 1
        else:
            break

    return sorted(arr), swaps + s1 + s2 + more_swaps


# Complete the countInversions function below.
def countInversions(arr):
    _, swaps = merge_sort_with_swaps(arr, 0)
    return swaps

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        result = countInversions(arr)

        fptr.write(str(result) + '\n')

    fptr.close()


"""
take sorted array O(nlogn)
compare elements in sorted and arr
for each element e,
    perform k swaps to get e in arr into the correct position according to sorted
    add k to the running total, and move onto the next element

O(n^2)
"""

"""
swaps are something that sorting inherently does
we need to implement sorting ourselves to keep track of a counter 
"""
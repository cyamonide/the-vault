#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumSwaps function below.
def minimumSwaps(arr):
  # in-place sort
  arr = [i-1 for i in arr]

  swaps_counter = 0

  hasSwapped = True
  while hasSwapped:
    hasSwapped = False
    for i, val in enumerate(arr):
      if val == i:
        continue
      elif arr[val] == i and arr[i] == val:
        swaps_counter += 1
        hasSwapped = True
        arr[val], arr[i] = val, i
      else:
        swaps_counter += 1
        hasSwapped = True
        arr[val], arr[i] = arr[i], arr[val]

  return swaps_counter


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = minimumSwaps(arr)

    fptr.write(str(res) + '\n')

    fptr.close()

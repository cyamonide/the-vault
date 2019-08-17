#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the makeAnagram function below.
def makeAnagram(a, b):
    da = {}
    db = {}
    for c in 'abcdefghijklmnopqrstuvwxyz':
        da[c] = 0
        db[c] = 0

    for c in a:
        da[c] += 1
    for c in b:
        db[c] += 1

    deletions = 0
    for c in 'abcdefghijklmnopqrstuvwxyz':
        deletions += max(da[c], db[c]) - min(da[c], db[c])

    return deletions

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = input()

    b = input()

    res = makeAnagram(a, b)

    fptr.write(str(res) + '\n')

    fptr.close()

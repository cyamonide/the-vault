#!/bin/python3

import math
import os
import random
import re
import sys

def getMiddles(n, s):
    count = 0

    for i, mid in enumerate(s):
        sideLetter = ''
        # how far out left/right are reaching
        for j in range(1, len(s)):
            # check if any of i-j or i+j are out of range
            left = i-j
            right = i+j
            if left < 0 or right >= len(s):
                break
            # check that the two letters match each other
            if s[left] != s[right]:
                break
            # check that the two letters are equal to our sideLetter, if it exists
            if sideLetter == '':
                sideLetter = s[left]
            elif sideLetter != s[left]:
                break
            # check that the side letter differs from our middle letter
            if sideLetter == mid:
                break # because we'll be double-counting otherwise
            count += 1

    return count

def getSames(n, s):
    count = 0
    last = ''
    thisCount = 0
    for c in s:
        if c != last:
            # add all possible sub-substrings to count
            count += (thisCount + 1) * thisCount * 0.5
            # start new substring
            last = c
            thisCount = 1
        elif c == last:
            thisCount += 1

    # handle last letter
    count += (thisCount + 1) * thisCount * 0.5

    return count

# Complete the substrCount function below.
def substrCount(n, s):
    return int(getSames(n, s) + getMiddles(n, s))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = substrCount(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()

#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'mystery' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING_ARRAY letter as parameter.
#

def mystery(letter):
    # Write your code here
    minOps = []

    for word in letter:
        opCount = 0
        for i in range(len(word) // 2):
            leftLetter = word[i]
            rightLetter = word[len(word) - i - 1]
            opCount += ord(max(leftLetter, rightLetter)) - ord(min(leftLetter, rightLetter))
        minOps.append(opCount)

    return minOps

if __name__ == '__main__':
    # code handing stdin/stdout
    pass
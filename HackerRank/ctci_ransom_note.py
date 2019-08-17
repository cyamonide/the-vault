#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
    m = {}
    for i in magazine:
        m[i] = m.get(i, 0) + 1
    for i in note:
        if m.get(i, 0) == 0:
            print('No')
            return
        else:
            m[i] -= 1
    print('Yes')


if __name__ == '__main__':
    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = input().rstrip().split()

    note = input().rstrip().split()

    checkMagazine(magazine, note)

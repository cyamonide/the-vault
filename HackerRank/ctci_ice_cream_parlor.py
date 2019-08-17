#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the whatFlavors function below.
def whatFlavors(cost, money):
    half = money // 2
    halves = []
    d = {}
    for i, c in enumerate(cost):
        d[c] = i
        if c == money // 2:
            halves.append(i+1)

    if 2*half == money and len(halves) == 2:
        halves.sort()
        print("{} {}".format(halves[0], halves[1]))
        return

    for c in cost:
        if d.get(money-c, False):
            print("{} {}".format(min(d[c], d[money-c])+1, max(d[c], d[money-c])+1))
            return

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        money = int(input())

        n = int(input())

        cost = list(map(int, input().rstrip().split()))

        whatFlavors(cost, money)

#!/bin/python3

def isSatisfied(excess, runningTotal):
    for c in excess:
        if runningTotal[c] < excess[c]:
            return False
    return True

def sol():
    n = int(input())
    gene = input()

    # determine character diffs
    diffs = {}
    # initialize diffs
    for c in "CGAT":
        diffs[c] = 0
    for c in gene:
        diffs[c] += 1
    # subtract a quarter of n
    for c in "CGAT":
        diffs[c] -= n // 4

    # filter character counts in excess
    e = {}
    for c in diffs:
        if diffs[c] > 0:
            e[c] = diffs[c]

    # case where gene is already balanced
    if len(e) == 0:
        print(0)
        return

    # dict counting characters in this substring
    runningTotal = {}
    for c in "CGAT":
        runningTotal[c] = 0

    shortest = n
    i = 0
    j = 0
    runningTotal[gene[j]] += 1
    while j < n:
        if isSatisfied(e, runningTotal):
            shortest = min(shortest, j - i + 1)
            i += 1
            runningTotal[gene[i-1]] -= 1
        else:
            j += 1
            if j >= n:
                break
            runningTotal[gene[j]] += 1

    print(shortest)

sol()
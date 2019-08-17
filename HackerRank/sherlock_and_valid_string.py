#!/bin/python3

def sol():
    s = input()

    d = {}
    for c in s:
        d[c] = d.get(c, 0) + 1

    counts = {}
    for c in d:
        counts[d[c]] = counts.get(d[c], 0) + 1

    # if there are more than two distinct counts, then string is invalid
    if len(counts) > 2:
        print('NO')
        return

    # if there is one (or less) distinct count, then string is valid
    if len(counts) <= 1:
        print('YES')
        return

    # at this point, there should be two distinct counts only

    if counts.get(1, 0) == 1:
        print('YES')
        return

    # if the two distinct counts differ by more than one, then string is invalid
    first, second = counts.keys()
    if abs(first - second) > 1:
        print('NO')
        return

    # if the larger of the two counts appears more than once, then not possible
    loc_max = max(first, second)
    if counts[loc_max] == 1:
        print('YES')
        return
    print('NO')

sol()
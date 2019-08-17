#!/bin/python3


def merge_sort(arr):
    n = len(arr)
    if n == 1:
        return arr
    p1 = merge_sort(arr[:n//2])
    p2 = merge_sort(arr[n//2:])
    new_arr = []
    while p1 or p2:
        if len(p1) and len(p2):
            if p1[0] < p2[0]:
                new_arr.append(p1.pop(0))
            else:
                new_arr.append(p2.pop(0))
        elif len(p1):
            new_arr += p1
            break
        else:
            new_arr += p2
            break

    return new_arr


print(merge_sort([9, 8, 7, 6, 5, 4, 3, 2, 1, 1]))
print(merge_sort([1, 2, 3, 4, 5, 6, 6, 7, 2]))

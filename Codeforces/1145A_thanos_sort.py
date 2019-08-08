#! /usr/bin/python

import math

def sol():
  def is_sorted(arr):
    for i in range(1, len(arr)):
      if arr[i] < arr[i-1]:
        return False

    return True

  n = int(input())
  a = list(map(int, input().split()))

  step_size = n # 2**m is size of range
  count = n // step_size


  while step_size > 1:
    for i in range(count):
      roi = a[i*step_size:(i+1)*step_size]
      if (is_sorted(roi)):
        print(step_size)
        return

    step_size //= 2
    count *= 2

  print(1)

sol()
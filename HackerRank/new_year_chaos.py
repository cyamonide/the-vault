#!/usr/bin/python

def sol(n, arr):
  # check if attainable
  arr = [i-1 for i in arr]

  # check that nobody has moved up more than two places
  for i, p in enumerate(arr):
    if (p - i) > 2:
      return "Too chaotic"
  
  # count number of bribes
  bribes = 0
  for cur, og in enumerate(arr):
    for i in range(max(0, og-1), cur):
      if arr[i] > og:
        bribes += 1

  return bribes

test_cases = int(input())

for _ in range(test_cases):
  n = int(input())
  arr = list(map(int, input().split()))

  print(sol(n, arr))
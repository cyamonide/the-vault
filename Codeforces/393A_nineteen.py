#! /usr/bin/python

import math

def sol():
  d = {}
  for i in "nineteen":
    d[i] = 0
  s = input()
  for i in s:
    d[i] = d.get(i, 0) + 1

  temp_min = (min(d['i'], d['e'] // 3, d['t']))
  print(min(temp_min, max(0, (d['n'] - 1) // 2)))

sol()
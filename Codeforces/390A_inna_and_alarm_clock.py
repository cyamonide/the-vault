#! /usr/bin/python

def sol():
  n = int(input())
  x = {}
  y = {}
  for i in range(n):
    x_i, y_i = map(int, input().split())
    x[x_i] = True
    y[y_i] = True

  print(min(len(x.keys()), len(y.keys())))

sol()
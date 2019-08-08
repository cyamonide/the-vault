#! /usr/bin/python

def sol():
  n, p, k = map(int, input().split())

  outstring = ""
  has_one = False
  has_n = False
  prefix = ""
  for i in range(p-k, p+k+1):
    if i == 1:
      has_one = True
    if i == n:
      has_n = True
    if i < 1 or i > n:
      continue
    else:
      if i == p:
        outstring += prefix + "({})".format(str(i))
      else:
        outstring += prefix + str(i)
      prefix = " "
  
  if not has_one:
    outstring = "<< " + outstring
  if not has_n:
    outstring += " >>"

  print(outstring)

sol()
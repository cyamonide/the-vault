#! /usr/bin/python

def sol():
  z = input()
  a = z.split('+')
  b = list(map(len, [a[0]] + a[1].split('=')))

  a, b, c = b

  if (a + b == c):
    # do nothing
    pass
  elif (a + b == c - 2):
    c -= 1
    a += 1
  elif (a + b == c + 2):
    if a == 1:
      b -= 1
      c += 1
    else:
      a -= 1
      c += 1
  else:
    print("Impossible")
    return

  exp = ""

  for i in range(a):
    exp += '|'
  exp += '+'

  for i in range(b):
    exp += '|'
  exp += '='

  for i in range(c):
    exp += '|'

  print(exp)

sol()
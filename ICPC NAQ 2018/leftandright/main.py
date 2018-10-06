# number of houses
n = int(input())
# movement
m = str(raw_input())

# generate list of houses
h = []
for i in xrange(1, n+1):
    h.append(i)

Lcount = 1
Rcount = 0

for a in m:
    if a == 'L':
        Lcount += 1

Rcount = n-Lcount

Lhouses = h[:Lcount]
Rhouses = h[Lcount:]



print(Lhouses)
print(Rhouses)

"""
# number of houses
n = int(input())

# movement
m = str(raw_input())

# generate list of houses
h = []
for i in xrange(1, n+1):
    h.append(i)

# houses visited, in this order
v = []

while len(h) > 0:
    this_move = m[0]
    m = m[1:]

    this_move_count = 1
    while len(m) > 0 and m[0] == this_move:
        this_move_count += 1
        m = m[1:]

    # starting position
    if this_move == 'R' and len(v) == 0:
        v = [1]
        h = h[1:]
    elif this_move == 'L' and len(v) == 0:
        v.append(h[this_move_count])
        h = h[:this_move_count] + h[this_move_count+1:]

    if this_move == 'L':
        for a in reversed(h[0:this_move_count]):
            v.append(a)
        h = h[this_move_count:]
    else:
        for a in h[-this_move_count:]:
            v.append(a)
        h = h[:-this_move_count]

print(v)
"""

""" start jason's solution """
"""
n = int(raw_input())
a = [0]*n
pos = 0
next_letter = 2
a[pos] = 1


seq = raw_input()

for s in seq:
    if s == "L":
        a = a[:pos] + [next_letter] + a[pos:len(a) - 1]
    if s == "R":
        while a[pos] != 0:
            pos += 1
        a[pos] = next_letter
        next_letter += 1

    print(a)

print("===")

for i in xrange(1,n+1,1):
    for n in xrange(len(a)):
        if a[n] == i:
            print n + 1
"""
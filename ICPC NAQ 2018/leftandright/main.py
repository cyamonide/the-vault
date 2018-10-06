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

while len(h) > 1:
    this_move = m[0]
    m = m[1:]

    this_move_count = 1
    while len(m) > 0 and m[0] == this_move:
        this_move_count += 1
        m = m[1:]

    if this_move == 'L':
        for a in reversed(h[0:this_move_count]):
            v.append(a)
        h = h[this_move_count:]
    else:
        for a in h[-this_move_count:]:
            v.append(a)
        h = h[:-this_move_count]

v = [h[0]] + v

print(v)
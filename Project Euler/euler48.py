prod = 0
digs = 10000000000

for i in range(1, 1001):
    prod += ((i%digs)**i)%digs
    prod %= digs

print(prod)

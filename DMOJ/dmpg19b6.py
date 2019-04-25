
from functools import reduce
import operator

# input

N, M = map(int, input().split())
costs = list(map(int, input().split()))

cols = []
for i in range(N):
    cols.append(list(map(int, input().split())))

# parity check

possible = True
for i in range(N-1):
    if (reduce(operator.add, cols[i], 0)) % 2 != (reduce(operator.add, cols[i+1], 0)) % 2:
        possible = False
        break

# print soln

if not possible:
    print(-1)
else:
    costs = sorted(costs)
    print(costs[0] + costs[1] if reduce(operator.add, cols[i], 0) % 2 else costs[0])
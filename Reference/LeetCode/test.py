from heapq import *

nums = [1, 6, 2, 3, 7, 1, 8, 3, 6, 8, 4, 6, 3, 4, 5, 1, 4]
k = len(nums) # k is 7

k_even = k%2==0

lo = sorted(nums)

if k_even:
    hi = lo[k//2:]
    lo = lo[:k//2]
else:
    hi = lo[k//2+1:]
    lo = lo[:k//2+1]

# change all values in lo to negative to implement max heap
lo = list(map((lambda x : -x), lo))

map((lambda x : heapify(x)), [hi, lo])

print lo, hi

invalid = []

meds = []

# compute first median
if k_even:
    meds.append((hi[0]-lo[0])/2.0)
else:
    meds.append(lo[0])

balance = 0

# get invalids
for j in range(k, len(nums)):
    # add new value to invalid
    if nums[k-j] in lo:
        balance -= 1
    else:
        balance += 1
    invalid.append(nums[k-j]):

    new = nums[j]

    if new >= hi[0]:
        heappush(hi, new)
        balance -= 1
    else:
        heappush(lo, -new)
        balance += 1

    while balance > 0:
        while -lo[0] in invalid:
            invalid.remove(-heappop(lo))
        while hi[0] in invalid:
            invalid.remove(heappop(hi))

        heappush(hi, -heappop(lo))
        balance -= 1

    while balance < 0:
        while -lo[0] in invalid:
            invalid.remove(-heappop(lo))
        while hi[0] in invalid:
            invalid.remove(heappop(hi))

        heappush(lo, -heappop(hi))
        balance += 1

    if k_even:
        meds.append((hi[0]-lo[0])/2.0)
    else:
        meds.append(lo[0])


while -lo[0] in invalid:
    invalid.remove(-heappop(lo))
while hi[0] in invalid:
    invalid.remove(heappop(hi))

print lo, hi

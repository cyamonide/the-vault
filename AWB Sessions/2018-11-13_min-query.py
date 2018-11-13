import math, sys

#      0  1  2  3  4  5  6  7
arr = [3, 2, 5, 7, 1, 0, 1, 3]

with open('test.in') as file:
	arr = map(int, file.readline().split())

# range lookups
l = {}

# generate min-ranges in l of length 1
for i in xrange(len(arr)):
	l[(i, i)] = arr[i]

# generate powers of 2
for i in xrange(1, int(math.floor(math.log(len(arr), 2)))+1):
	w = int(2**i)
	for i in xrange(0, len(arr)-w+1):
		l[(i, i+w-1)] = min(l[(i, i+(w//2)-1)], l[(i+(w//2), i+w-1)])

def query(a, b):
	k = int(2**(math.floor(math.log(b-a+1, 2))))
	print(min(l[a, a+k-1], l[b-k+1, b]))

print('length of arr: ' + str(len(arr)))
query(0, 3)
query(0, 1000)
query(1000, 2000)
query(0, 99999)

"""
Searches for n in A
"""
def binarySearch(A, n):
	first = 0
	last = len(A)-1
	found = False

	while first <= last and not found:
		midpoint = (first + last) // 2
		if A[midpoint] == n:
			found = True
		else:
			if n < A[midpoint]:
				last = midpoint-1
			else:
				first = midpoint+1

	return found

"""
Searches for n in A recursively
"""
def binarySearchR(A, n):
	if len(A) == 0:
		return False
	else:
		midpoint = len(A) // 2
		if A[midpoint] == n:
			return True
		else:
			if n < A[midpoint]:
				return binarySearchR(A[:midpoint], n)
			else:
				return binarySearchR(A[midpoint+1:], n)

testlist = [0, 1, 2, 8, 13, 17, 18, 32, 42,]

print(binarySearch(testlist, 2))
print(binarySearchR(testlist, 2))
print(binarySearch(testlist, 4))
print(binarySearchR(testlist, 4))

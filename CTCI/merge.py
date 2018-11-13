
def mergeSort(A):
	# do nothing if singular element
	if len(A) > 1:

		# find midpoint
		mid = len(A)//2
		# split
		lefthalf = A[:mid]
		righthalf = A[mid:]

		# sort left half and right half
		mergeSort(lefthalf)
		mergeSort(righthalf)

		# i keeps track of left half index
		# j keeps track of right half index
		# k keeps track of total operations (not really used)
		i, j, k = 0, 0, 0

		# do the merge
		while i < len(lefthalf) and j < len(righthalf):
			if lefthalf[i] < righthalf[j]:
				A[k] = lefthalf[i]
				i += 1
			else:
				A[k] = righthalf[j]
				j += 1
			k += 1

		# copy leftover from lefthalf
		while i < len(lefthalf):
			A[k] = lefthalf[i]
			i += 1
			k += 1
			# if you're extra, i, k = map(lambda x : x+1, [i, k])

		# copy leftover from righthalf
		while j < len(righthalf):
			A[k] = righthalf[j]
			j += 1
			k += 1

A = [1, 5, 2, 7, 7, 3, 4, 7, 2, 9]

mergeSort(A)

print A
# implement a quicksort

def quickSort(arr, left, right):
	if left >= right:
		return

	index = partition(arr, left, right)

	if left < index - 1:
		quickSort(arr, left, index - 1)
	if index < right:
		quickSort(arr, index, right)

def partition(arr, left, right):
	pivot = arr[(left + right) // 2]
	print pivot
	while left <= right:
		print arr
		while arr[left] < pivot:
			left += 1
		while arr[right] > pivot:
			right -= 1

		# swap elements and move left and right indices
		if left <= right:
			arr[left], arr[right] = arr[right], arr[left]
			left += 1
			right -= 1

	return left

# foo = [2, 6, 1, 4, 4, 7, 3, 8]
foo = [2, 3, 5, 6, 7, 8, 1, 4]

print foo

quickSort(foo, 0, len(foo)-1)

print "sorted:" + str(foo)
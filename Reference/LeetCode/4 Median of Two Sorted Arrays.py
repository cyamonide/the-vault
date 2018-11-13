
def median(A, B):
	m, n = len(A), len(B)

	if m > n: # swap two arrays (we want len(A) < len(B))
		A, B, m, n = B, A, n, m

	if n == 0:
		raise ValueError


	imin = 0
	imax = m
	half_len = (m + n + 1) / 2 # +1 is for lengths

	while imin <= imax:
		# reindex A with i, B with j
		i = (imin + imax) / 2
		j = half_len - i
		# note that we want i + j = half_len

		if i < m and B[j-1] > A[i]:
			# i is too small; must increase
			# bottom left to top right comparison
			imin = i+1
		elif i > 0 and A[i-1] > B[j]:
			# is is too large; must decrease
			# top right to bottom left comparison
			imax = i-1
		else:
			# i is perfect

			if i == 0:
				max_of_left = B[j-1]
			elif j == 0:
				max_of_left = A[i-1]

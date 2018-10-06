# 3 - Sorting

## 3.1 - Sorting theory

A basic problem in sorting: given an array of $n$ elements, sort the elements in increasing order.

### Bubble

Simple sorting algorithms work in $O(n^2)$ time. For example, bubble sort.

```c++
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n-1; j++) {
		// if arr[i] and arr[j] are out of order, swap
	}
}
```

### Merge

Merge sort, however, works in $O(n \log{n} )$ time. This algorithm divides the main array into subarrays, then recursively sorts the subarrays.  
Because the subarrays are smaller in size, sorting is quicker. Also, because the subarrays end up sorting, merging is done in linear time.

### Inversions

A useful concept when analyzing sorting algorithms is the __inversion__, a pair of array elements that are out of order and need to be swapped.

* The number of inversions indicates how much work is needed to sort the array
* An array is completely sorted when there are no inversions

### Counting

Also known as bookkeeping sort, a __counting sort__ sorts an array in $O(n)$ time assuming every element in the array is an integer between $0$ and $c$, where $O(n) = c$.

Essentially, you create a frequency table and reconstruct an array in sorted order.

## 3.2 - Sorting in C++

It is almost never a good idea to use a home-made sorting algorithm in a contest.

Sort a vector in increasing order:
```c++
vector<int> v = { 4, 2, 5, 3, 5, 8, 3};
sort(v.begin(), v.end());
```

Sort a vector in decreasing order:
```c++
sort(v.rbegin(), v.rend());
// or alternatively,
sort(v.begin(), v.end(), greater<int>());
// where greater<int>() is the comparison operator for sorting greatest to least
```

Sort an array:
```c++
int n = 7; // array size
int a[] = {4, 2, 5, 3, 5, 8, 3};
sort(a, a+n);
sort(a, a+n, greater<int>());
```

Sort a string:
```c++
string s = "monkey";
sort(s.begin(), s.end());
```

### Comparison operators

#### Built-in

To sort in decreasing order (from greatest to least), use the `greater<type>()` operator.

Tuples are sorted according to their first elements, then their second, then their third, etc.

#### User-defined structs

The operator should be defined inside the struct as a function `operator<` whose parameter is another element of the same type.

```c++
struct P {
	int x, y;
	bool operator<(const P &p) { // less than operator
		// sort by x coord primarily, if not equal
		if (x != p.x) return x < p.x;
		// sort by y coord otherwise
		else return y < p.y;
	}
}
```

#### Comparison functions

It is also possible to give an external comparison function to the `sort` function.

```c++
bool comp(string a, string b) {
	// sort primarily by string size
	if (a.size() != b.size()) return a.size() < b.size();
	// sort alphabetically otherwise
	return a < b;
}

// a vector of strings can now be sorted as follows
sort(v.begin(), v.end(), comp);
```

## 3.3 - Binary search

A general method to search for an element in an array is to iterate through all elements using a for loop. This time complexity is $O(n)$.

If the array is sorted, __binary search__ may be used to find an element in $O(\log{n})$ time.

```c++
int a = 0, b = n-1; // initial left and right bounds
while (a <= b) {
	int k = (a+b)/2; // midpoint index
	if (array[k] == x) {
		// x found at index k
	}
	if (array[k] > x) b = k-1; // lower higher bound
	else a = k+1; // raise lower bound
}
```
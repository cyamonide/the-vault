# 2 - Time Complexity

## 2.1 - Calculation rules

Complexity denoted as $O(...)$ where the three dots are a function.

```c++
// This code has complexity O(n)
for (int i = 1; i <= n; i++) {
    // code
}

// This code has complexity O(n^2)
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        // code
    }
}
```

### Phases

Total time complexity is largest time complexity of a single phase. Think bottleneck.

```c++
// Time complexity of this snippet is O(n^2)

// Phase 1
for (int i = 1; i <= n; i++) {
    // code
}
// Phase 2
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        // code
    }
}
```

### Several variables

With several variables,
```c++
// Time complexity is O(nm)
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        // code
    }
}
```

### Recursion

With recursion, time complexity depends on:
* number of times a function is called
* time complexity of a single call

```c++
// Recursive example 1
void f(int n) {function
    if (n == 1) return;
    f(n-1);
}
```

In the above example, the time complexity of each call is $O(1)$ and `f(n)` causes $n$ function calls. Therefore, the total time complexity is $O(n)$.

```c++
// Recursive example 2
void g(int n) {
    if (n == 1) return;
    g(n-1);
    g(n-1);
}
```

In the second example, each function call generates two other calls, except for $n=1$. Based on this, time complexity is $1 + 2 + 4 + ... + 2^(n-1) = 2^n - 1 = O(2^n)$.

## 2.2 - Complexity classes

* $O(1)$
    * __Constant time algorithm__
    * Does not depend on input size
    * Typically a direct formula that calculates answer
    * See Binet's formula for Fibonacci numbers (section 1.5)
* $O(\log{n})$
    * __Logarithmic algorithm__
    * Often halves input size at each step
* $O\sqrt{n}$
    * __Square root algorithm__
    * Slower than $O(\log{n})$ but faster than $O(n)$
* $O(n)$
    * __Linear algorithm__
    * Often the best possible time complexity because it is _usually_ necessary to access each input element at least once before reporting the answer
* $O(n \log{n})$
    * Usually indicates algorithm sorts input
    * For example, `for each element, function to search sorted array to insert`
        * Algorithm uses a data structure where each operation takes $O(\log{n})$ time
* $O(2^n)$
    * Indicates algorithm iterates through all subsets of input elements
* $O(n!)$
    * Indicates algorithm iterates through all permutations of input elements

An algorithm is __polynomial__ if its time complexity is at most $O(n^k)$where $k$ is a constant. In practice, $k$ is usually small and therefore the algorithm is _efficient_.

__NP-hard__ problems are problems for which no polynomial algorithm is known.

## 2.3 - Estimating efficiency

Starting point for estimations is the fact that a modern computer can perform __hundreds of millions__ of operations a second.

Assume the time limit for a problem is one second, and that the input size is $10^5$. With $O(n^2)$ time complexity, the algorithm will perform in $(10^5)^2$ operations. This would take tens of seconds, since $10^{10} = 10^8 \times 100$.

Generally, where $n$ is an overestimation of the number of seconds taken to complete the algorithm, $10^k = 10^8 \times n$.

```
input size  required time complexity
n <= 10     O(n!)
n <= 20     O(2^n)
n <= 500    O(n^3)
n <= 5000   O(n^2)
n <= 10^6   O(n log n) or O(n)
n is large  O(1) or O(log n)
```

## 2.4 Maximum subarray sum

Given an array of $n$ numbers, calculate the maximum subarray sum (i.e. the largest possible sum of a sequence of consecutive values in the array).

__Algorithm 1__

Go through all possible subarrays.
```c++
for (firstIndex = 0; firstIndex < n; firstIndex++) {
	for (secondIndex = firstIndex; secondIndex < n; secondIndex++) {
		// sum values from first index to second (another for loop)
		// compare to best subarray sum thus far
	}
}
```
The time complexity of this algorithm is $O(n^3)$.

__Algorithm 2__

This is an optimization of the first one. See reference.

__Algorithm 3__

This problem is solvable in $O(n)$ time.

Consider the problem of finding the max-sum subarray that ends at position $k$. There are two possibilities:
1. The subarray only contains the element at position $k$
2. The subarray contains of some subarray that ends at $k-1$, followed by the element at $k$

The solution is the best out of these two possibilities as we iterate k over the elements of the array.

```c++
int best = 0; // this is the best answer thus far
int sum = 0; // this is the max sum terminating at k-1

for (int k = 0; k < n; k++) { // iterate our index k from 0 to n
	// find max sum terminating at k
	sum = max(array[k], sum+array[k]);
	// update best
	best = max(best, sum);
}
```
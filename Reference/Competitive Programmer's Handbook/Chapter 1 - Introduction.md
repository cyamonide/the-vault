# 1 - Introduction

## 1.1 - Languages

`#include <bits/stdc++.h>` will include all c++ standard libraries  

`-02` option in `g++` optimizes code  

## 1.2 - I/O

```
// optimizing IO
ios::sync_with_stdio(0);
cin.tie(0);
```  

`\n` works faster than `endl` because the latter calls a flush operation every time

```
// reading integers using scanf

int a, b;
scanf("%d %d", &a, &b);
```

```
// printing integers using printf

printf("%d %d\n", a, b);
```

```
// read entire line

string s;
getline(cin, s);
```

```
// unknown amount of data

while (cin >> x) {
    // code
}
```

```
// reading from file IO

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

## 1.2 - Working with numbers

32-bit signed `integer` has range 2^31, or roughly 2x10^9.  
64-bit signed `long long` has range 2^63 or about 9x10^18.  
Unsigned types can make use of leading bit: can store larger positive numbers.  

### Modular arithmetic
Take modulus before adding, subtracting, or multiplying  
To prevent negative modulo, add `m`

### Floating point numbers
`double` is 64-bit  
`long double` is 80-bit and more accurate  

```
// output floating point numbers

printf("%.9f", x);
```

Due to rounding error, it may be risky to use the `==` operator.  
A better way to compare is to use an epsilon value - `E = 1e-9` in practice.  
```
if (abs(a-b) < 1e-9) {
    // a and b are equal
}
```

## 1.5 - Mathematics
### Sum formulae
Faulhaber?  
__harmonic sum__ has upper bound log_2(n)+1
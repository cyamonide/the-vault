# 1 - C++ basics

## 1.7 - Forward declarations
```c++
int add(int x, int y);
// now use add before it is implemented
```

## 1.8 - Programs with multiple files
Forward declare the functions you reference in one file but are defined in another.

`add.cpp`:
```c++
int add(int x, int y) {
	return x + y;
}
```

`main.cpp`:
```c++
#include <iostream>

int add(int x, int y);

int main() {
	add(3, 4);
}
```

## 1.8a - Naming conflicts and the std namespace
Namespaces prevent naming conflicts with our own identifiers.
```c++
std::cout << "Hello world!";
```

## 1.9 - Header files
__Header files__ also known as __include files__, with extensions `.h`, `.hpp`, or sometimes no extension at all

```c++
#include <iostream>
int main() {
	std::cout << "Hello, world!" << std::endl;
	return 0;
}
```
The program never defines `cout` but knows what it is because it is declared in the `iostream` header file.

Header files typically only contain declarations, and _do not define how something is implemented_. When we use `#include <iostream>`, `cout` is actually implemented in the C++ runtime support library, automatically linked to your program during the link phase.

<hr>

First part of a header file is the __header guard__, preventing a given header file to be #included more than once in the same file.

Second part is the actual content of the file, which should be declarations for all functions we want other files to be able to see.

`add.h`:
```c++
// This is the start of the header guard.
// ADD_H can be any unique name. By convention, we use the name of the header file.
#ifndef ADD_H
#define ADD_H

// this is the content of the .h file
int add(int x, int y);

// this is the end of the header guard.
#endif
```

To use this header file, we have to include it.

```c++
#include <iostream>
#include "add.h"

int main() {
	// insert code here
}
```

`add.cpp`:
```c++
int add(int x, int y) {
	return x + y;
}
```

When you #include a file, the entire content of the included file is inserted at the point of inclusion.

<hr>

Use \<angle brackets\> to include header files that are in _system directories_.  
"Quotes" are for header files we supply.

If the header file isn't found in the project directory, the compiler will begin looking in other include paths and finally default to system directories.

Each .cpp file should explicitly #include all of the header files it needs to compile. In other words, don't use `#include <bits/stdc++.h>`.
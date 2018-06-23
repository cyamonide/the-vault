# 1 - C++ basics

## 1.7 - Forward declarations
```c++
int add(int x, int y);
// now use add before it is implemented
```

## 1.8 - Programs with multiple files
Forward declare the functions you reference in one file but are defined in another.

add.cpp:
```c++
int add(int x, int y) {
	return x + y;
}
```

main.cpp:
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

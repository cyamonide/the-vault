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

### Header file rules

Use \<angle brackets\> to include header files that are in _system directories_.  
"Quotes" are for header files we supply.

If the header file isn't found in the project directory, the compiler will begin looking in other include paths and finally default to system directories.

Each .cpp file should explicitly #include all of the header files it needs to compile. In other words, don't use `#include <bits/stdc++.h>`.

Use the non `.h` version of a header file if it exists, and access the functionality through the `std` namespace. If not, or you are creating your own headers, use the `.h` version.

<hr>

To include header files from other directories, tell the compiler or IDE where to look for those files. This can be done by setting an include path.

Using `g++`, you can use the `-I` option to specify an alternate include directory.

```
$ g++ -o main -I /source/includes main.cpp
```

## 1.10 - A first look at the preprocessor

A __preprocessor__ is essentially a separate program that runs just before the compiler. It scans the code and looks for __directives__, which are specific instructions that start with `#` and end in a newline `\n`. 

<hr>

### Includes

When you `#include` a file, the preprocessor copies the entire contents of the file at the point of the #include statement.

`#include <filename>` tells the preprocessor to look in system directories.  
`#include "filename"` tells the preprocessor to look in the project directory. It will then look in system directories upon failing.

### Macro defines

The `#define` directive can be used to create a macro.

There are two basic types of macros: __object-like macros__ and __function-like macros__. The latter is very dangerous and shall not be mentioned.

Object-like macros can be defined in two ways:
```c++
#define identifier
#define identifier substitution_text
```

With substitution text, any further occurrence of `identifier` is replaced by `substitution_text`. Without substitution text, `identifier` is replaced by nothing.

Read more about these in section _2.9 - Const, constexpr, and symbolic constants_

_Note: macros only cause substitution in normal code, and not other directives._

### Conditional compilation

The three directives covered in this section are `#ifdef`, `#ifndef`, and `#endif`.

### The scope of defines

Directives are only valid from the point of definition to the end of the file in which they are defined. Directives in one code file do not have an impact on other files.

## 1.10a - Header guards

Header guards prevent duplicate definitions, which cause compilation errors.

```c++
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// declarations and definitions here

#endif
```

By convention, `SOME_UNIQUE_NAME_HERE` is the name of the file.

`math.h:`
```c++
#ifndef MATH_H
#define MATH_H

// stuff

#endif
```

<hr>

### Side note - Difference between declaration and definition

__Declaration__ Tells compiler about type, size, and in case of function declaration, the type and size of its parameters.  
__Definition__ is declaration + space reservation.

```c++
// examples of declarations
extern int a;
struct _tagExample { int a; int b; };
int myFunc (int a, int b);

// examples of definitions
int a;
int b = 0;
int myFunc (int a, int b) { return a + b; }
struct _tagExample example;
```

[Source](https://www.tutorialspoint.com/What-is-the-difference-between-a-definition-and-a-declaration-in-Cplusplus)

<hr>

### #pragma once
`#pragma once` serves the same purpose as header guards, and has the added benefit of being shorter and less error-prone.

This is not an official part of the C++ language, though most modern compilers support it. For compatibility purposes, don't use it.

## 1.11 - Debugging your program (stepping and breakpoints)

__Semantic errors__ occur when a statement is syntactically valid, but does not do what the programmer intended.
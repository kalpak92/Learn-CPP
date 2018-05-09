# What is the proper declaration of main?

### What is the proper signature of the `main` function in C++?  

The `main` function must be declared as a **non-member function in the global namespace**. This means that it cannot be a static or non-static member function of a class, nor can it be placed in a namespace (even the unnamed namespace).

The name `main` is not reserved in C++ except as a function in the global namespace. You are free to declare other entities named `main`, including among other things, classes, variables, enumerations, member functions, and non-member functions not in the global namespace.

You can declare a function named `main` as a member function or in a namespace, but such a function would not be the `main` function that designates where the program starts.

The `main` function cannot be declared as `static` or `inline`. It also cannot be overloaded; there can be only one function named `main` in the global namespace.

The `main` function cannot be used in your program: you are not allowed to call the `main` function from anywhere in your code, nor are you allowed to take its address.

### What is the correct return type? What are the allowed parameter types, and what are their meanings?

**The return type of main must be int**. No other return type is allowed (this rule is in bold because it is very common to see incorrect programs that declare `main` with a return type of `void`; this is probably the most frequently violated rule concerning the `main` function).

There are two declarations of `main` that must be allowed:

```c++
int main()               // (1)
int main(int, char*[])   // (2)
```

In **(1)**, there are no parameters.

In **(2)**, there are two parameters and they are conventionally named `argc` and `argv`, respectively.`argv` is a pointer to an array of C strings representing the arguments to the program. `argc` is the number of arguments in the `argv` array.

Usually, `argv[0]` contains the name of the program, but this is not always the case. `argv[argc]` is guaranteed to be a null pointer.

Note that since an array type argument (like `char*[]`) is really just a pointer type argument in disguise, the following two are both valid ways to write **(2)** and they both mean exactly the same thing:

```c++
int main(int argc, char* argv[])
int main(int argc, char** argv)
```

###  What does it mean to return a value from `main`? 

`main()` is expected to return zero to indicate success and non-zero to indicate failure. You are not required to explicitly write a `return` statement in `main()`: if you let `main()` return without an explicit `return` statement, it's the same as if you had written `return 0;`. The following two `main()`functions have the same behavior:

```c++
int main() { }
int main() { return 0; }
```

There are two macros, `EXIT_SUCCESS` and `EXIT_FAILURE`, defined in `<cstdlib>` that can also be returned from `main()` to indicate success and failure, respectively.

The value returned by `main()` is passed to the `exit()` function, which terminates the program.

### Is this system-specific? Have those rules changed over time? What happens if I violate them?

Note that all of this applies only when compiling for a hosted environment (informally, an environment where you have a full standard library and there's an OS running your program). It is also possible to compile a C++ program for a freestanding environment (for example, some types of embedded systems), in which case startup and termination are wholly implementation-defined and a `main()` function may not even be required. If you're writing C++ for a modern desktop OS, though, you're compiling for a hosted environment.



# C++ 14 says

The exact wording of the latest published standard (C++14) is:

> An implementation shall allow both
>
> - a function of `()` returning `int` and
> - a function of `(int`, pointer to pointer to `char)` returning `int`
>
> as the type of `main`.

This makes it clear that alternative spellings are permitted so long as the type of `main` is the type `int()` or `int(int, char**)`. So the following are also permitted:

- `int main(void)`
- `auto main() -> int`
- `int   main (    )`
- `signed int main()`
- `typedef char **a; typedef int b, e; e main(b d, a c)`

# C 11 says

```c
int main(void);
int main(int argc, char* argv[]);
```

although it does mention the phrase "or equivalent" with the following footnote:

> Thus, `int` can be replaced by a `typedef` name defined as `int`, or the type of `argv` can be written as `char ** argv`, and so on.

In addition, it also provides for more (implementation-defined) possibilities.

The relevant section (section 5.1.2.2.1 in C11, but this particular aspect is unchanged from C99) states:

> The function called at program startup is named main. The implementation declares no prototype for this function. It shall be defined with a return type of int and with no parameters:
>
> ```c
> int main(void) { /* ... */ }
> ```
>
> or with two parameters (referred to here as argc and argv, though any names may be used, as they are local to the function in which they are declared):
>
> ```c
> int main(int argc, char *argv[]) { /* ... */ }
> ```
>
> or equivalent; or in some other implementation-defined manner.
>
> If they are declared, the parameters to the main function shall obey the following constraints:
>
> - The value of `argc` shall be nonnegative.
> - `argv[argc]` shall be a null pointer.
> - If the value of argc is greater than zero, the array members `argv[0]` through `argv[argc-1]`inclusive shall contain pointers to strings, which are given implementation-defined values by the host environment prior to program startup. The intent is to supply to the program information determined prior to program startup from elsewhere in the hosted environment. If the host environment is not capable of supplying strings with letters in both uppercase and lowercase, the implementation shall ensure that the strings are received in lowercase.
> - If the value of `argc` is greater than zero, the string pointed to by `argv[0]` represents the program name; `argv[0][0]` shall be the null character if the program name is not available from the host environment. If the value of `argc` is greater than one, the strings pointed to by `argv[1]` through `argv[argc-1]` represent the program parameters.
> - The parameters `argc` and `argv` and the strings pointed to by the `argv` array shall be modifiable by the program, and retain their last-stored values between program startup and program termination.

# Common Extension

Classically, Unix systems support a third variant:

```c
int main(int argc, char **argv, char **envp) { ... }
```

The third argument is a null-terminated list of pointers to strings, each of which is an environment variable which has a name, an equals sign, and a value (possibly empty). If you do not use this, you can still get at the environment via '`extern char **environ;`'. For a long time, that did not have a header that declared it, but the [POSIX](http://en.wikipedia.org/wiki/POSIX) 2008 standard now requires it to be declared in `<unistd.h>`.

This is recognized by the C standard as a common extension, documented in Annex J:

> ### J.5.1 Environment arguments
>
> ¶1 In a hosted environment, the main function receives a third argument, `char *envp[]`, that points to a null-terminated array of pointers to `char`, each of which points to a string that provides information about the environment for this execution of the program (5.1.2.2.1).


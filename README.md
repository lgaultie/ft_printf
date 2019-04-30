ft_printf
===

## What is ft_printf?

This project is about recoding the famous printf C function to learn variadic functions and improve algorithmic methodology.

```
int ft_printf(const char * (restrict) format, ...);
```

ft_printf can print different contents depending on conversions and flags. 
You can print using the following syntax: 

```
%[flag][min-width].[precision][length modifier][conversion specifier]
```
min-width depending on cases, will add empty spaces.
Precision, depending on cases, will add '0'.

See below what are flags, length modifier and conversions.


## Features

Conversions:
```
c    char
s    char *
p    void * (to print pointer's adress)
f    floats
u    unsigned int
o    unsigned int (octal)
x/X: unsigned int (hexadecimal)
d/i: int
```
flags:
```
-       Left align.
+       Sign of number always O/P.
space   Positive values begin with a space.
0       Field is padded with 0's instead of space.
#       has different uses:
  %#o   0 prefix inserted.
  %#x   0x prefix added to non-zero values.
  %#X   0X prefix added to non-zero values.
```
length modifiers:
```
h       short
l       long
L       long double
```

## Usage

You can try our project with the following commands:

First, clone the repository
```
git clone https://github.com/lgaultie/ft_printf
cd ft_printf
make
```
then compile your file with the generated **libftprintf.a** by adding in the main 
```
#include "src/ft_printf.h"
```
and use it like the real printf function.

## Example

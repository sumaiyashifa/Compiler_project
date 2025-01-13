# Custom Language Compiler

A compiler implementation using Flex and Bison that supports a custom programming language with variables, functions, control structures, and string operations.

## Table of Contents

- [Features](#features)
- [Built-in Functions](#built-in)
- [Data-types](#data-types)
- [Prerequisites](#prerequisites)
- [Control Structures](#control-structures)
- [Project Structure](#project-structure)
- [Building and Running](#building-and-running)
- [Examples](#sample-programs)
- [References](#references)

## Features

- Multiple data types (INTEGER, FLOAT, STRING, CHARACTER)
- Function definitions with parameters
- Control structures (if-else, switch-case, loops)
- Mathematical and string operations
- Type checking and error handling

## Built-in Functions

Mathematical: sin, cos, tan, log, ln
Number Theory: factorial, isPrime
Utilities: max, min, isOddEven
String Operations: strjoin (concatenation)

## Data Types

- INTEGER - Integer values
- FLOAT - Floating point numbers
- STRING - Text strings
- CHARACTER - Single characters

## Prerequisites

- Flex (Fast Lexical Analyzer)
- Bison (Parser Generator)
- GCC (GNU Compiler Collection)

## Control Structures

- If-else conditionals
- Switch-case statements
- For loops
- While loops
- Comments

## Project Structure

- 2007031.l - Flex lexical analyzer
- 2007031.y - Bison parser grammar
- input.txt - Sample input program
- output.txt - Generated output
- abc.sh - Build script

## Building and Running

1. Ensure you have Flex and Bison installed
2. Generate the lexical analyzer:

````
flex 2007031.l
``````

````
bison -d 2007031.y
``````
````
gcc lex.yy.c 2007031.tab.c -o app.exe
``````
````
./app.exe
````





## Examples
See the included input.txt for sample programs demonstrating language features.
The compiler provides detailed output including:
- Variable declarations and assignments
- Function calls and parameters
- Expression evaluation results
- Control flow execution
- Error messages and type checking
## References

- [Flex Manual](https://westes.github.io/flex/manual/)
- [Bison Manual](https://www.gnu.org/software/bison/manual/)
- [Writing Compilers and Interpreters: A Software Engineering Approach](https://www.amazon.com/Writing-Compilers-Interpreters-Software-Engineering/dp/0470177071)



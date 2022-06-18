# Monty Bytecode Interpreter

### Documentation

## Installation
- compile with the following:
  - gcc -Wall -Werror -Wextra -pedantic *.c -o monty
  - usage: ./monty <filename>
    - filename should contain the Operators
    - One operator per line
    - spaces and newlines are ignored
    - '#' sign represent comments and the line will be ignored

## Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

- monty.h - contains all the structure and prototype
- main.c - main function for monty interpreter

## Operator Instruction
- push - pushes value to stack
  - usage: push 123
- pall - prints everything on the stack LIFO
  - usage: pall

### Authors
BRIGHT OKON

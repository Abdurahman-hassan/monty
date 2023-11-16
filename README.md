# Monty Interpreter

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (similar to Python). It relies on a unique stack with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Table of Contents

 - [Installation](#installation)
 - [Usage](#usage)
 - [Supported Opcodes](supported-opcodes)
 - [Examples](#examples)
 - [Authors](#authors)

 ## Installation

Clone the interperter repository on your machine:
```bash
git clone https://github.com/Abdurahman-hassan/monty.git
```

Navigate to the repository folder:
```bash
cd monty
```

Compile your C source code as follows:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

## Usage

Use the following command to execute monty bytecode files:
```bash
./monty <file>
```
Where <file> is the path to the file containing Monty bytecode

## The supported Opcodes

```push:``` Adds a new node with a given value to the top of the stack.\
```pall:``` Prints all the values on the stack, starting from the top.\
```pint:``` Prints the value at the top of the stack.\
```pop:``` Removes the top element from the stack.\
```swap:``` Swaps the top two elements of the stack.\
```nop:``` The opcode nop doesn’t do anything.\
```add:``` Adds the top two elements of the stack together.\
```sub:``` Subtracts the top two elements of the stack.\
```div:``` Divides the second element from the top of the stack by the top element, and replaces the top element with the result.\
```mul:``` Multiplies the top two elements of the stack.\
```mod:``` Computes the remainder of the division of the second top element of the stack by the top element.\
```#:``` Treat the line as a comment.\
```pchar:``` Prints the ASCII character corresponding to the top element of the stack.\
```pstr:``` Prints the ASCII characters represented by the elements in the stack.\
```rotl:``` Rotates the stack to the top, moving the top element to the bottom.\
```rotr:``` Rotates the stack to the bottom, moving the bottom element to the top.\
```stack:``` Sets the format of the data to a stack (LIFO). This is the default behavior of the program.\
```queue:``` Sets the format of the data to a queue (FIFO).\

## Examples

**1. push and pall opcodes**

The command:
```bash
./monty bytecodes/push_pall.m
```

The output:
```
3
2
1
```

**2. pop opcode**

The command:
```bash
./monty bytecodes/pop.m
```

The output:
```
3
2
1
2
1
1
```

**3. stack and queue opcodes**

The command:
```bash
./monty bytecodes/stack_queue.m
```

The output:
```
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
```

## Authors

This project was built by [Abdulrahman Hassan](https://github.com/Abdurahman-hassan) and [Mojtaba Mohamed](https://github.com/mojmo) as part a of ALX SE program for 0x19. C - Stacks, Queues - LIFO, FIFO Project.





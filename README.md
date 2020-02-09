# Project 1

Due date: February 23 at 11:59pm.

**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own.
Any sharing or copying of assignments will be considered plagiarism (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**

The `Makefile` provided with this project compiles and builds all of the required programs.
To compile and build all of the programs run:

    make all

To compile and build individual problems run:

    make problem1
    make problem2
    ...

To run programs for each problem you can either execute

    ./problem1
    ./problem2
    ...

or, you can use the rules defined in the `Makefile`:

    make run_problem1
    make run_problem2
    ...

Finally, to run programs using `valgrind` you can use the rules
defined in the `Makefile`:

    make test_prob1
    make test_prob2
    ...

To remove all previously compiled and built files, run

    make clean


## Problem 1 (30 points)

You just got a position as a research assistant in Professor Threon's lab.
Your first task is to write a program that finds locations of all the genes
encoding Threonine.

To complete this task, you will need a [DNA codon table](https://en.wikipedia.org/wiki/DNA_codon_table). Your program needs to analyze
the DNA strand and determine the locations of the triples that encode Threonine.  Those triples are ACT, ACC, ACA, ACG.  

__Example:__

Input DNA sequence: ATGACACGGAGTACGTAA

The locations of the triples encoding Threonine are: 3 (ACA) and 12 (ACG).<br>
Notice that the __location 5 is not__ an answer, since every triple has to start
on a multiple of three index (otherwise triples would overlap).

__Error handling and output__:

If the program is given an invalid strand (i.e., one that contains characters
    other that A, T, C, and G), it should print -1 and terminate.

If the program is given a valid strand that does not contain even one triple, the program should print 0 and terminate.

If the program is given a valid strand that contains one or more triples, it should
print the indexes of the first character of the triple, one per line. In the above
example, the output should be:<br>
3<br>
12<br>


_Note_: You should assume that the input sequence is all in uppercase. You can treat all lowercase letters as invalid characters. The maximum length of the sequence that your program needs to handle is 9,999.  


HINT: You might find the functions provided by the string library useful for solving this problem. You can learn more about them by reading the man page for `string.h` header file:
```
man string.h
```
(this is available on `crackle1`, but not in CS50 IDE).

__Deliverables:__

Implement your program in the file `problem1.c`. The part of the `main` function
responsible for reading the DNA strand is already there.



## Problem 2 (40 points)


This program performs basic operations on a binary search tree.
It reads a sequence of instructions from the standard input stream
and outputs the results to the standard output stream.

The program accepts the following instructions:

- `add value` add the `value` to the tree
- `min` remove and return the smallest value stored in the current tree (should have no effect
  if the current tree is empty)
- `max` remove and return the largest value stored in the current tree (should have no effect
  if the current tree is empty)
- `print` print the values stored in the current tree in order of the inorder traversal

The `main` function in `problem2.c` reads and parses the input stream and calls
appropriate functions to perform the instructions. __Your task is to implement
those functions so that the output produced by the program is correct.__


__Example__

__Input:__
```
add park
add snow
add zoo
add car
add dinner
print
min
max
print
add crab
add rank
add herb
add rabbit
add sand
print
max
min
print
min
min
max
max
print
max
min
print
min
print
```

__Output:__
```
car dinner park snow zoo
dinner park snow
crab dinner herb park rabbit rank sand snow
dinner herb park rabbit rank sand
park rabbit


```
(notice that the last two lines of the output are blanks since the tree is empty at that point!).



__Deliverables:__
Implementation of the functions in `bst.c` file. You may add
declarations to the file `bst.h` (you have to upload the modified
  file if you do so), but you are not allowed to modify the function signatures that
  are currently listed in the file `bst.h`.

You should not modify `problem2.c` file.


## Problem 3 (30 points)

We define the operation of splitting a binary number `n` into two numbers
`a`, `b` as follows. Let `0 ≤ i1 < i2 < ... < ik` be the indices of the bits (with
the least significant bit having index 0) in `n` that are 1. Then the indices of the bits
of `an` that are 1 are `i1` , `i3` , `i5` , ... and the indices of the bits of `bn`
that are 1 are `i2` , `i4` , `i6` ,  ...

For example, if `n` is `110110101` in binary then, again in binary, we have `a =
010010001` and `b = 100100100`.

__Input__

The program reads a value of `n` and produces two values
`a` and `b` as described above.

Your program should handle integer values of
`n` between 1 and 2^(31) - 1 (i.e. all positive integers within the range of the `int` type)
written in standard decimal (base 10) format.

_Note_: Your program should not prompt the user for anything. Assume that the user
will enter a single value, as described above, unprompted. Your program does not
need to validate the input. You are guaranteed that it will be a positive integer
as described above.

__Output__

The output should contain the integers
`a` and `b` separated by a single space. Both `a` and `b` should be written in decimal format (base 10).


__Examples__


|Input: | Output: |
|:---:|:---:|
| `6` | `2 4` |
| `7` | `5 2` |
| `13`| `9 4` |




__Restrictions__

Your program is not allowed to use ANY of the functions defined in the `math.h` header file.
Specifically, it is not allowed to use the `pow()` functions to compute values of powers of 2.




__Deliverables__

Implementation of the program in `problem3.c` file.

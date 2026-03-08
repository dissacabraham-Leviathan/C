# Data Structures Tutorial - IV

**Course:** 23EC415 - DATA STRUCTURES AND ALGORITHMS  
**Academic Year:** 2025-26  
**Topics Covered:** UNIT-2: array, recursion, expression evaluation, stack, queue

## Problems

### Problem 1: Array and Recursion
- **1a. Duplicate Elements** (`problem1_duplicate_elements.c`)
  - Count total number of duplicate elements in an array
  - Array elements derived from register number digits

- **1b. Fibonacci Series** (`problem1_fibonacci_recursion.c`)
  - Generate Fibonacci series using recursion

### Problem 2: Stack Operations (`problem2_stack_operations.c`)
- Push register number digits and pop 5 elements
- Find maximum and minimum element in stack

### Problem 3: Queue Operations (`problem3_queue_operations.c`)
- Insert elements (register number) and dequeue 5 elements
- Count elements and print front and rear positions

### Problem 4: Expression Conversion (`problem4_infix_to_postfix.c`)
- Convert infix to postfix expression
- Supported operators: +, -, *, /
- Parentheses supported: ()

## Compilation and Execution

To compile any program:
```bash
gcc problem1_duplicate_elements.c -o duplicate
gcc problem1_fibonacci_recursion.c -o fibonacci
gcc problem2_stack_operations.c -o stack
gcc problem3_queue_operations.c -o queue
gcc problem4_infix_to_postfix.c -o infix
```

To run:
```bash
./duplicate
./fibonacci
./stack
./queue
./infix
```

## Notes
- All programs include proper comments and structure
- Each file is organized with clear headings
- Input validation and error handling included

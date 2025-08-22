# Chapter 1: Introduction to programming in C

This guide provides a structured progression of exercises to help you learn C programming from the fundamentals to more advanced concepts.

## Getting Started

1. **Hello, World!**
   - Create a program that prints "Hello, World!" to the console
   - Learn about the main function and basic program structure

2. **Personal Information Printer**
   - Write a program that prints your name, email, and a fun fact about yourself
   - Practice using printf() with different text strings

3. **ASCII Art**
   - Create a program that displays a simple pattern or picture using ASCII characters
   - Explore multiline printing and character formatting

## Variables and Basic Operations

4. **Data Types Practice**
   - Declare variables of different data types (int, float, double, char)
   - Initialize them with values and print them out
   - Demonstrate the size and range of each data type using sizeof()

5. **Simple Calculator**
   - Create a program that takes two numbers as input
   - Perform addition, subtraction, multiplication, and division
   - Display the results of each operation

6. **Temperature Converter**
   - Write a program that converts temperatures between Celsius and Fahrenheit
   - Implement both C to F and F to C conversions
   - Formula: C = (F - 32) * 5/9, F = C * 9/5 + 32

7. **Geometry Calculator**
   - Calculate the area and perimeter of:
     - Circle (A = πr², P = 2πr)
     - Rectangle (A = l×w, P = 2l + 2w)
     - Triangle (A = ½bh, P = a + b + c)
   - Use #define or const for values like PI

## Control Flow

8. **Even or Odd Checker**
   - Create a program that determines if a number is even or odd
   - Use the modulo operator (%) and if-else statements

9. **Leap Year Detector**
   - Write a program to check if a given year is a leap year
   - Rule: A year is a leap year if it's divisible by 4, except for years divisible by 100 but not by 400

10. **Grade Calculator**
    - Take a numerical score as input (0-100)
    - Output the corresponding letter grade:
      - A: 90-100
      - B: 80-89
      - C: 70-79
      - D: 60-69
      - F: Below 60

11. **Menu-Driven Program**
    - Create a simple program with a menu of options
    - Use switch-case to perform different actions based on user selection
    - Include options like basic calculations, unit conversions, etc.

## Loops

12. **Number Printer**
    - Display all numbers from 1 to N (user input)
    - Implement using for, while, and do-while loops
    - Add variations like printing only even or odd numbers

13. **Factorial Calculator**
    - Calculate the factorial of a number N (N!)
    - Handle edge cases (negative numbers, zero)
    - Consider limitations for large numbers

14. **Fibonacci Sequence Generator**
    - Generate and display the Fibonacci sequence up to N terms
    - The sequence starts with 0, 1 and each subsequent number is the sum of the two preceding ones

15. **Multiplication Table Generator**
    - Create a program that prints the multiplication table for a given number
    - Format the output to align columns properly

16. **Sum and Average Calculator**
    - Take N numbers as input
    - Calculate and display their sum and average
    - Practice using running sums in loops

## Arrays

17. **Min-Max Finder**
    - Create an array of integers
    - Find and display the largest and smallest elements
    - Keep track of the positions of these elements

18. **Array Statistics**
    - Calculate the sum, average, and standard deviation of elements in an array
    - Count how many elements are above/below the average

19. **Array Reversal**
    - Write a program that reverses the elements of an array in-place
    - Print the array before and after reversal

20. **Linear Search**
    - Implement a simple linear search algorithm
    - Search for a user-specified element in an array
    - Return the position(s) where the element is found

21. **Bubble Sort**
    - Implement the bubble sort algorithm to sort an array
    - Display the array after each pass to visualize the sorting process
    - Count and display the number of comparisons and swaps

## Functions

22. **Math Function Library**
    - Create functions for various mathematical operations:
      - Power function (x^y)
      - Absolute value
      - GCD and LCM
      - Prime number checker

23. **Geometry Functions**
    - Write a program with separate functions for:
      - Circle area and circumference
      - Rectangle area and perimeter
      - Triangle area (using different formulas)
    - Create a menu to select which calculation to perform

24. **Recursive Functions**
    - Implement recursive functions for:
      - Factorial calculation
      - Fibonacci sequence
      - GCD using Euclidean algorithm
    - Compare performance with iterative versions

25. **Prime Number Functions**
    - Create a function to check if a number is prime
    - Write a function to display all prime numbers up to N
    - Implement the Sieve of Eratosthenes algorithm for finding primes

## Strings

26. **String Analyzer**
    - Count the number of characters, words, and lines in a string
    - Calculate frequency of each character
    - Find the longest word

27. **String Reversal**
    - Reverse a string character by character
    - Compare different methods (using a temporary array vs. in-place)
    - Handle special cases like strings with spaces

28. **Palindrome Checker**
    - Check if a string is a palindrome (reads the same forward and backward)
    - Make it case-insensitive
    - Ignore spaces and punctuation

29. **Case Converter**
    - Convert a string to uppercase or lowercase
    - Create a function to toggle the case of each character
    - Implement title case (first letter of each word capitalized)

30. **Substring Search**
    - Search for a substring within a string
    - Return all positions where the substring is found
    - Implement a simple version of the string.h functions

## Next Steps

After completing these exercises, consider exploring:
- File I/O
- Structures and unions
- Dynamic memory allocation
- Pointers and advanced pointer concepts
- Preprocessor directives
- Multi-file programs
- Data structures (linked lists, stacks, queues)

Remember to practice good coding habits:
- Comment your code
- Use meaningful variable names
- Check for edge cases
- Validate user input
- Format your code consistently
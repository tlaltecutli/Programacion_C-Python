# Complete Guide: C Data Types and Operations

## Introduction

The C programming language is a statically-typed, middle-level language that provides direct control over system resources. Understanding data types and basic operations is fundamental to writing efficient and correct C programs. This guide covers all essential aspects of data manipulation in C.

## Chapter 1: Data Types in C

### 1.1 Integer Types

C provides several integer types with different sizes and ranges:

#### char
- **Size**: 1 byte (8 bits)
- **Range**: -128 to 127 (signed) or 0 to 255 (unsigned)
- **Primary use**: Character storage and small integers
- **Memory efficient**: Best for storing ASCII characters

```c
char letter = 'A';
char ascii_value = 65;  // Equivalent to 'A'
unsigned char byte_value = 255;
```

#### short (short int)
- **Size**: 2 bytes (16 bits)
- **Range**: -32,768 to 32,767
- **Use case**: Small integers when memory conservation is important

```c
short year = 2024;
short temperature = -15;
```

#### int
- **Size**: Typically 4 bytes (32 bits) on most modern systems
- **Range**: -2,147,483,648 to 2,147,483,647
- **Primary use**: General-purpose integer arithmetic

```c
int age = 25;
int population = 1000000;
```

#### long (long int)
- **Size**: At least 4 bytes (often 8 bytes on 64-bit systems)
- **Range**: System dependent
- **Use case**: Large integers beyond int range

```c
long distance = 1000000000L;  // Note the 'L' suffix
```

#### long long
- **Size**: 8 bytes (64 bits)
- **Range**: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
- **Use case**: Very large integers

```c
long long star_distance = 9460730472580800LL;  // Light-year in km
```

### 1.2 Floating-Point Types

#### float
- **Size**: 4 bytes (32 bits)
- **Precision**: ~6-7 decimal digits
- **Range**: ±3.4E±38
- **Use case**: General floating-point arithmetic

```c
float price = 19.99f;        // Note the 'f' suffix
float pi_approx = 3.14159f;
```

#### double
- **Size**: 8 bytes (64 bits)
- **Precision**: ~15-16 decimal digits
- **Range**: ±1.7E±308
- **Use case**: High-precision calculations (default for floating literals)

```c
double precise_pi = 3.141592653589793;
double scientific = 1.23e-4;  // Scientific notation
```

#### long double
- **Size**: System dependent (typically 10, 12, or 16 bytes)
- **Precision**: Higher than double
- **Use case**: Maximum precision calculations

```c
long double ultra_precise = 3.141592653589793238L;
```

### 1.3 Type Modifiers

#### signed and unsigned
- **signed**: Can store both positive and negative values (default for most types)
- **unsigned**: Only positive values, doubles the positive range

```c
unsigned int positive_only = 4294967295U;
signed int can_be_negative = -2000000000;

// Common unsigned combinations
unsigned char byte = 255;
unsigned short port = 8080;
unsigned long id = 123456789UL;
```

### 1.4 Type Size Verification

```c
#include <stdio.h>

int main() {
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    return 0;
}
```

## Chapter 2: Constants and Literals

### 2.1 Defining Constants

#### Using #define Preprocessor Directive
```c
#define PI 3.14159
#define MAX_STUDENTS 100
#define WELCOME_MESSAGE "Hello, World!"
#define NEWLINE '\n'
```

#### Using const Keyword (Preferred Method)
```c
const int MAX_ATTEMPTS = 3;
const float GRAVITY = 9.81f;
const char SEPARATOR = ',';
const double E = 2.718281828;
```

### 2.2 Literal Types
```c
// Integer literals
int decimal = 42;
int octal = 052;        // Octal (starts with 0)
int hexadecimal = 0x2A; // Hexadecimal (starts with 0x)

// Floating-point literals
float f_literal = 3.14f;
double d_literal = 3.14;
double scientific = 1.5e-3;  // 0.0015

// Character literals
char single_char = 'A';
char escape_char = '\n';     // Newline
char tab_char = '\t';        // Tab
```

## Chapter 3: Arithmetic Operations

### 3.1 Basic Arithmetic Operators

| Operator | Description | Example | Result Type |
|----------|-------------|---------|-------------|
| `+` | Addition | `5 + 3` | Same as operands |
| `-` | Subtraction | `10 - 4` | Same as operands |
| `*` | Multiplication | `7 * 2` | Same as operands |
| `/` | Division | `15 / 3` | Same as operands |
| `%` | Modulo (remainder) | `17 % 5` | Integer only |

### 3.2 Important Division Behavior

```c
#include <stdio.h>

int main() {
    // Integer division truncates
    int int_result = 7 / 3;        // Result: 2 (not 2.33)
    
    // Floating-point division
    float float_result = 7.0f / 3.0f;  // Result: 2.333333
    
    // Mixed division (promotion occurs)
    float mixed_result = 7 / 3.0f;     // Result: 2.333333
    
    // Explicit casting
    float cast_result = (float)7 / 3;   // Result: 2.333333
    
    printf("Integer division: %d\n", int_result);
    printf("Float division: %.6f\n", float_result);
    printf("Mixed division: %.6f\n", mixed_result);
    printf("Cast division: %.6f\n", cast_result);
    
    return 0;
}
```

### 3.3 Modulo Operator Specifics

```c
// Modulo only works with integers
int remainder = 17 % 5;  // Result: 2
int negative = -17 % 5;  // Result: -2 (sign follows dividend)

// Common uses of modulo
int is_even = (number % 2 == 0);  // Check if even
int last_digit = number % 10;     // Get last digit
int wrap_around = index % array_size;  // Circular indexing
```

## Chapter 4: Assignment Operations

### 4.1 Simple Assignment
```c
int x = 10;       // Initialization
x = 20;           // Assignment
```

### 4.2 Compound Assignment Operators

| Operator | Equivalent | Description |
|----------|------------|-------------|
| `+=` | `x = x + y` | Add and assign |
| `-=` | `x = x - y` | Subtract and assign |
| `*=` | `x = x * y` | Multiply and assign |
| `/=` | `x = x / y` | Divide and assign |
| `%=` | `x = x % y` | Modulo and assign |

```c
int value = 10;
value += 5;   // value = 15
value -= 3;   // value = 12
value *= 2;   // value = 24
value /= 4;   // value = 6
value %= 4;   // value = 2
```

### 4.3 Increment and Decrement Operators

```c
int a = 5, b = 5;

// Pre-increment: increment first, then use value
int pre_inc = ++a;   // a = 6, pre_inc = 6

// Post-increment: use value first, then increment
int post_inc = b++;  // b = 6, post_inc = 5

// Same logic applies to decrement
int c = 8, d = 8;
int pre_dec = --c;   // c = 7, pre_dec = 7
int post_dec = d--;  // d = 7, post_dec = 8
```

## Chapter 5: Comparison and Logical Operations

### 5.1 Comparison Operators

| Operator | Description | Returns |
|----------|-------------|---------|
| `==` | Equal to | 1 (true) or 0 (false) |
| `!=` | Not equal to | 1 (true) or 0 (false) |
| `<` | Less than | 1 (true) or 0 (false) |
| `<=` | Less than or equal | 1 (true) or 0 (false) |
| `>` | Greater than | 1 (true) or 0 (false) |
| `>=` | Greater than or equal | 1 (true) or 0 (false) |

```c
int x = 5, y = 10;
int equal = (x == y);        // 0 (false)
int not_equal = (x != y);    // 1 (true)
int less = (x < y);          // 1 (true)
int greater = (x > y);       // 0 (false)
```

### 5.2 Logical Operators

| Operator | Description | Behavior |
|----------|-------------|----------|
| `&&` | Logical AND | Short-circuit evaluation |
| `\|\|` | Logical OR | Short-circuit evaluation |
| `!` | Logical NOT | Unary operator |

```c
int age = 20;
int has_license = 1;

// Logical AND
if (age >= 18 && has_license) {
    printf("Can drive\n");
}

// Logical OR
if (age < 18 || !has_license) {
    printf("Cannot drive\n");
}

// Logical NOT
int is_minor = !(age >= 18);
```

### 5.3 Short-Circuit Evaluation

```c
int x = 0;
int y = 5;

// In AND operation, if first operand is false, second is not evaluated
if (x != 0 && y / x > 2) {  // Safe: y/x won't execute if x == 0
    printf("Safe division\n");
}

// In OR operation, if first operand is true, second is not evaluated
if (x == 0 || y / x > 2) {  // y/x won't execute if x == 0
    printf("Either x is zero or division result > 2\n");
}
```

## Chapter 6: Type Conversions

### 6.1 Implicit Conversion (Automatic)

C automatically promotes types in expressions following these rules:
1. `char` and `short` → `int`
2. `float` → `double` in function arguments
3. Lower precision → Higher precision in mixed expressions

```c
char c = 'A';
int i = 10;
float f = 3.14f;
double d = 2.718;

int result1 = c + i;      // char promoted to int
double result2 = f + d;   // float promoted to double
double result3 = i + d;   // int promoted to double
```

### 6.2 Explicit Conversion (Casting)

```c
float pi = 3.14159f;
int truncated = (int)pi;  // 3 (decimal part lost)

int numerator = 7, denominator = 3;
float division = (float)numerator / denominator;  // 2.333333

// Casting between different integer types
long big_number = 1000000L;
int smaller = (int)big_number;  // Potential data loss if too large
```

### 6.3 Conversion Warnings and Best Practices

```c
// Potential data loss warnings
int large = 300;
char small = (char)large;  // Data loss: 300 > 255 (char range)

// Safe conversions
unsigned int positive = 100;
int signed_value = (int)positive;  // Safe if within range

// Floating-point precision considerations
float f = 1.23456789f;     // Only ~6-7 digits precision
double d = (double)f;      // Doesn't add precision, just extends format
```

## Chapter 7: Operator Precedence and Associativity

### 7.1 Precedence Table (High to Low)

| Priority | Operators | Associativity | Description |
|----------|-----------|---------------|-------------|
| 1 | `()` `[]` `->` `.` | Left to Right | Primary |
| 2 | `!` `~` `++` `--` `+` `-` `*` `&` `sizeof` | Right to Left | Unary |
| 3 | `*` `/` `%` | Left to Right | Multiplicative |
| 4 | `+` `-` | Left to Right | Additive |
| 5 | `<` `<=` `>` `>=` | Left to Right | Relational |
| 6 | `==` `!=` | Left to Right | Equality |
| 7 | `&&` | Left to Right | Logical AND |
| 8 | `\|\|` | Left to Right | Logical OR |
| 9 | `=` `+=` `-=` `*=` `/=` `%=` | Right to Left | Assignment |

### 7.2 Precedence Examples

```c
// Without parentheses
int result1 = 2 + 3 * 4;        // 14, not 20 (* before +)
int result2 = 10 - 6 / 2;       // 7, not 2 (/ before -)

// With parentheses for clarity
int result3 = (2 + 3) * 4;      // 20
int result4 = (10 - 6) / 2;     // 2

// Mixed operations
int complex = 2 + 3 * 4 > 10;   // 1 (true): (2 + 12) > 10
```

## Chapter 8: Input/Output Operations

### 8.1 Output with printf()

#### Common Format Specifiers

| Specifier | Data Type | Description | Example |
|-----------|-----------|-------------|---------|
| `%d` | int | Decimal integer | `printf("%d", 42)` |
| `%u` | unsigned int | Unsigned integer | `printf("%u", 42U)` |
| `%ld` | long | Long integer | `printf("%ld", 42L)` |
| `%f` | float/double | Floating-point | `printf("%f", 3.14)` |
| `%e` | float/double | Scientific notation | `printf("%e", 3.14)` |
| `%g` | float/double | Shortest representation | `printf("%g", 3.14)` |
| `%c` | char | Single character | `printf("%c", 'A')` |
| `%s` | char* | String | `printf("%s", "Hello")` |

#### Formatting Options

```c
int number = 42;
float pi = 3.14159f;

printf("Basic: %d\n", number);
printf("Width: %5d\n", number);           // Right-aligned in 5 spaces
printf("Left-aligned: %-5d|\n", number);  // Left-aligned
printf("Zero-padded: %05d\n", number);    // Padded with zeros

printf("Float: %f\n", pi);
printf("Precision: %.2f\n", pi);          // 2 decimal places
printf("Scientific: %e\n", pi);
printf("Compact: %g\n", pi);
```

### 8.2 Input with scanf()

```c
int age;
float height;
char grade;
char name[50];

printf("Enter your age: ");
scanf("%d", &age);  // Note the & (address-of operator)

printf("Enter your height: ");
scanf("%f", &height);

printf("Enter your grade: ");
scanf(" %c", &grade);  // Space before %c to skip whitespace

printf("Enter your name: ");
scanf("%s", name);     // No & for arrays
```

### 8.3 Safe Input Handling

```c
#include <stdio.h>

int main() {
    int number;
    char buffer[100];
    
    printf("Enter a number: ");
    
    // Safe input with error checking
    if (scanf("%d", &number) == 1) {
        printf("You entered: %d\n", number);
    } else {
        printf("Invalid input!\n");
        // Clear input buffer
        while (getchar() != '\n');
    }
    
    return 0;
}
```

## Chapter 9: Practical Examples

### 9.1 Advanced Calculator

```c
#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;
    
    printf("=== SCIENTIFIC CALCULATOR ===\n");
    printf("Supported operations: +, -, *, /, ^, s(sqrt), l(log)\n");
    
    printf("Enter first number: ");
    scanf("%lf", &num1);
    
    printf("Enter operator: ");
    scanf(" %c", &operator);
    
    if (operator != 's' && operator != 'l') {
        printf("Enter second number: ");
        scanf("%lf", &num2);
    }
    
    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0.0) {
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;
        case '^':
            result = pow(num1, num2);
            printf("%.2f ^ %.2f = %.2f\n", num1, num2, result);
            break;
        case 's':
            if (num1 >= 0) {
                result = sqrt(num1);
                printf("sqrt(%.2f) = %.2f\n", num1, result);
            } else {
                printf("Error: Cannot take square root of negative number!\n");
                return 1;
            }
            break;
        case 'l':
            if (num1 > 0) {
                result = log(num1);
                printf("ln(%.2f) = %.2f\n", num1, result);
            } else {
                printf("Error: Cannot take logarithm of non-positive number!\n");
                return 1;
            }
            break;
        default:
            printf("Error: Invalid operator!\n");
            return 1;
    }
    
    return 0;
}
```

### 9.2 Type Conversion Demonstration

```c
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("=== C DATA TYPE DEMONSTRATION ===\n\n");
    
    // Integer types and their limits
    printf("INTEGER TYPES:\n");
    printf("char: %d to %d (size: %zu bytes)\n", CHAR_MIN, CHAR_MAX, sizeof(char));
    printf("short: %d to %d (size: %zu bytes)\n", SHRT_MIN, SHRT_MAX, sizeof(short));
    printf("int: %d to %d (size: %zu bytes)\n", INT_MIN, INT_MAX, sizeof(int));
    printf("long: %ld to %ld (size: %zu bytes)\n", LONG_MIN, LONG_MAX, sizeof(long));
    
    // Floating-point types
    printf("\nFLOATING-POINT TYPES:\n");
    printf("float: precision %d digits (size: %zu bytes)\n", FLT_DIG, sizeof(float));
    printf("double: precision %d digits (size: %zu bytes)\n", DBL_DIG, sizeof(double));
    printf("long double: precision %d digits (size: %zu bytes)\n", LDBL_DIG, sizeof(long double));
    
    // Conversion examples
    printf("\nCONVERSION EXAMPLES:\n");
    
    int int_val = 42;
    float float_val = 3.14159f;
    char char_val = 'A';
    
    printf("Original values:\n");
    printf("int: %d, float: %.5f, char: %c (%d)\n", 
           int_val, float_val, char_val, char_val);
    
    // Implicit conversions
    printf("\nImplicit conversions:\n");
    printf("int to float: %d -> %.2f\n", int_val, (float)int_val);
    printf("float to int: %.5f -> %d\n", float_val, (int)float_val);
    printf("char to int: '%c' -> %d\n", char_val, (int)char_val);
    
    // Arithmetic with mixed types
    printf("\nMixed arithmetic:\n");
    float mixed_result = int_val + float_val;
    printf("int + float: %d + %.5f = %.5f\n", int_val, float_val, mixed_result);
    
    return 0;
}
```

### 9.3 Unit Converter

```c
#include <stdio.h>

int main() {
    int choice;
    double input, result;
    
    printf("=== UNIT CONVERTER ===\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Kilograms to Pounds\n");
    printf("6. Pounds to Kilograms\n");
    printf("Enter your choice (1-6): ");
    
    scanf("%d", &choice);
    
    printf("Enter the value to convert: ");
    scanf("%lf", &input);
    
    switch(choice) {
        case 1:
            result = (input * 9.0/5.0) + 32.0;
            printf("%.2f°C = %.2f°F\n", input, result);
            break;
        case 2:
            result = (input - 32.0) * 5.0/9.0;
            printf("%.2f°F = %.2f°C\n", input, result);
            break;
        case 3:
            result = input * 3.28084;
            printf("%.2f meters = %.2f feet\n", input, result);
            break;
        case 4:
            result = input / 3.28084;
            printf("%.2f feet = %.2f meters\n", input, result);
            break;
        case 5:
            result = input * 2.20462;
            printf("%.2f kg = %.2f lbs\n", input, result);
            break;
        case 6:
            result = input / 2.20462;
            printf("%.2f lbs = %.2f kg\n", input, result);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    
    return 0;
}
```

## Chapter 10: Best Practices and Common Pitfalls

### 10.1 Best Practices

1. **Always initialize variables**
   ```c
   int counter = 0;        // Good
   int undefined_var;      // Dangerous - contains garbage
   ```

2. **Use appropriate data types**
   ```c
   unsigned int age = 25;     // Age cannot be negative
   float price = 19.99f;      // Use float for currency calculations
   const int MAX_SIZE = 100;  // Constants for fixed values
   ```

3. **Be explicit with type conversions**
   ```c
   float result = (float)numerator / denominator;  // Clear intent
   ```

4. **Use parentheses for clarity**
   ```c
   int result = (a + b) * (c - d);  // Clear precedence
   ```

5. **Check for division by zero**
   ```c
   if (denominator != 0) {
       result = numerator / denominator;
   } else {
       printf("Error: Division by zero!\n");
   }
   ```

### 10.2 Common Pitfalls

1. **Integer division truncation**
   ```c
   int wrong = 5 / 2;        // Result: 2, not 2.5
   float correct = 5.0f / 2; // Result: 2.5
   ```

2. **Floating-point comparison**
   ```c
   // Wrong way
   if (float_value == 3.14) { ... }
   
   // Better way
   #include <math.h>
   if (fabs(float_value - 3.14) < 0.001) { ... }
   ```

3. **Overflow and underflow**
   ```c
   unsigned char value = 255;
   value++;  // Result: 0 (overflow wraparound)
   
   signed char small = -128;
   small--;  // Undefined behavior (underflow)
   ```

4. **Modulo with negative numbers**
   ```c
   int result = -17 % 5;  // Result: -2 (not 3)
   ```

5. **Assignment vs. comparison**
   ```c
   int x = 5;
   if (x = 3) { ... }     // Assignment! Always true (x becomes 3)
   if (x == 3) { ... }    // Comparison - this is what you want
   ```

### 10.3 Debugging Tips

1. **Use printf for debugging**
   ```c
   printf("Debug: x = %d, y = %d\n", x, y);
   ```

2. **Check variable values at key points**
   ```c
   printf("Before calculation: a = %d\n", a);
   result = complex_calculation(a);
   printf("After calculation: result = %d\n", result);
   ```

3. **Validate input**
   ```c
   if (scanf("%d", &number) != 1) {
       printf("Invalid input!\n");
       return 1;
   }
   ```

## Conclusion

Understanding C data types and operations is crucial for effective programming. This comprehensive guide covers:

- Complete data type system with sizes and ranges
- All arithmetic, logical, and comparison operations
- Type conversion mechanisms and best practices
- Input/output formatting and error handling
- Real-world examples and practical applications
- Common pitfalls and how to avoid them

Mastering these fundamentals will provide a solid foundation for advanced C programming concepts like pointers, arrays, structures, and memory management.

## Quick Reference

### Essential Headers
```c
#include <stdio.h>     // Input/output functions
#include <limits.h>    // Integer type limits
#include <float.h>     // Floating-point type limits
#include <math.h>      // Mathematical functions
```

### Type Checking Macros
```c
sizeof(type)    // Size of type in bytes
INT_MAX        // Maximum int value
FLT_DIG        // Float precision in digits
```

### Safe Programming Patterns
```c
// Safe division
if (b != 0) result = a / b;

// Safe input
if (scanf("%d", &var) == 1) { /* process */ }

// Safe comparison for floats
if (fabs(f1 - f2) < EPSILON) { /* equal */ }
```

---

*Complete Guide to C Data Types and Operations - Advanced Programming Reference*
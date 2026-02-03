/*
 * Simple calculator module for basic arithmetic operations
 */

#include "calculator.h"
#include <math.h>

/* Basic arithmetic operations */
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

float divide(int a, int b)
{
    if (b == 0) {
        return 0.0f; /* Division by zero protection */
    }
    return (float)a / (float)b;
}

/* Advanced operations */
int power(int base, int exponent)
{
    int result = 1;
    int i;
    
    if (exponent < 0) {
        return 0; /* Simplified - only handle positive exponents */
    }
    
    for (i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int factorial(int n)
{
    if (n < 0) {
        return -1; /* Invalid input */
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int is_prime(int n)
{
    int i;
    
    if (n <= 1) {
        return 0; /* Not prime */
    }
    if (n <= 3) {
        return 1; /* 2 and 3 are prime */
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0; /* Even numbers and multiples of 3 are not prime */
    }
    
    for (i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

/* Utility functions */
float square_root(float x)
{
    if (x < 0) {
        return -1.0f; /* Invalid input */
    }
    return sqrt(x);
}

int absolute_value(int x)
{
    return (x < 0) ? -x : x;
}

/* Additional utility functions */
int greatest_common_divisor(int a, int b)
{
    int temp;
    
    a = absolute_value(a);
    b = absolute_value(b);
    
    if (a == 0) return b;
    if (b == 0) return a;
    
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int digit_sum(int n)
{
    int sum = 0;
    
    n = absolute_value(n);
    
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
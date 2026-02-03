#ifndef _calculator_h_
#define _calculator_h_

/* Basic arithmetic operations */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

/* Advanced operations */
int power(int base, int exponent);
int factorial(int n);
int is_prime(int n);

/* Utility functions */
float square_root(float x);
int absolute_value(int x);
int greatest_common_divisor(int a, int b);
int digit_sum(int n);

#endif /* _calculator_h_ */
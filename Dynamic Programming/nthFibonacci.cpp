#include <stdio.h>

typedef unsigned long long int ULLI;

/**
 * Time Complexity O(2^n)
 * Space Complexity O(1)
*/
ULLI naiveNthFibonacci(int n) {
  if (n <= 1) return n;

  return naiveNthFibonacci(n - 1) + naiveNthFibonacci(n - 2); 
}

/**
 * Time Complexity O(n)
 * Space Complexity O(1)
*/
ULLI bottomUpNthFibonacci(int n) {
  ULLI a = 1, b = 1, temp;

  for (ULLI i = 2; i < n; i++) {
    temp = a + b;
    a = b;
    b = temp;
  }

  return b;
}

/**
 * Time Complexity O(n)
 * Space Complexity O(n)
*/
ULLI memo[100] = {0};
ULLI topDownNthFibonacci(int n) {
  if (n <= 1) return n;

  if (memo[n] != 0) return memo[n];

  return memo[n] = topDownNthFibonacci(n - 1) + topDownNthFibonacci(n - 2);
}

int main() {
  printf("%llu\n", naiveNthFibonacci(9));
  printf("%llu\n", topDownNthFibonacci(90));
  printf("%llu\n", bottomUpNthFibonacci(90));
  
  return 0;
}
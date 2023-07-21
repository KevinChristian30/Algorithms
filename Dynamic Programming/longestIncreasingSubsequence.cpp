#include <stdio.h>

#define MAX(a, b) (a > b ? a : b)

/**
 * Time Complexity O(2^n)
 * Space Complexity O(1)
*/
int naiveLongestIncreasingSubsequence(int sequence[], int length, int* max) {
  if (length == 1) return 1;
  
  int res, maxEndingHere = 1;
  for (int i = 1; i < length; i++) {
    res = naiveLongestIncreasingSubsequence(sequence, i, max);
  
    if (sequence[i - 1] < sequence[length - 1] && res + 1 > maxEndingHere) maxEndingHere = res + 1;
  }

  if (maxEndingHere > *max) *max = maxEndingHere;

  return maxEndingHere;
}

/**
 * Time Complexity O(n^2)
 * Space Complexity O(1)
*/
int dynamicProgrammingLongestIncreasingSubsequence(int sequence[], int length) {
  int tab[length];
  for (int i = 0; i < length; i++) tab[i] = 1;
  int maxLength = 1;

  for (int i = length - 1; i >= 0; i--) {
    for (int j = i + 1; j < length; j++) {
      if (sequence[i] < sequence[j]) {
        tab[i] = MAX(tab[i], 1 + tab[j]);
        if (tab[i] > maxLength) maxLength = tab[i];
      }
    }
  }

  return maxLength;
}      

int main() {
  int sequence[] = { 3, 10, 2, 11 };
  int length = sizeof(sequence) / sizeof(int);

  int max = 1;
  naiveLongestIncreasingSubsequence(sequence, length, &max);
  printf("%d\n", max);
  
  printf("%d\n", dynamicProgrammingLongestIncreasingSubsequence(sequence, length));
  
  return 0;
}
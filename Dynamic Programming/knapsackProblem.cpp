#include <stdio.h>

int max(int a, int b) {
  return a > b ? a : b;
}

/**
 * Time Complexity O(2^n)
 * Space Complexity O(1) [Needs Stack Memory O(n)]
*/
int naiveKnapsackProblem(int capacity, int weights[], int values[], int itemIndex) {
  if (capacity == 0 || itemIndex < 0) return 0;

  int take = 
    values[itemIndex] + naiveKnapsackProblem(capacity - weights[itemIndex], weights, values, itemIndex - 1);
  int notTake = naiveKnapsackProblem(capacity, weights, values, itemIndex - 1);

  return weights[itemIndex] > capacity ? notTake : max(take, notTake);
}

/**
 * Time Complexity (capacity * number of items)
 * Space Complexity (capacity * number of items) [Needs Stack Memory O(n)]
*/
int memo[1000][1000] = {0};
int dynamicProgrammingKnapsackProblem(int capacity, int weights[], int values[], int itemIndex) {
  if (capacity == 0 || itemIndex < 0) return 0;

  if (memo[capacity][itemIndex] != 0) return memo[capacity][itemIndex];

  int take = values[itemIndex] + naiveKnapsackProblem(capacity - weights[itemIndex], weights, values, itemIndex - 1);
  int notTake = naiveKnapsackProblem(capacity, weights, values, itemIndex - 1); 
  
  return memo[capacity][itemIndex] = 
    weights[itemIndex] > capacity ? notTake : max(take, notTake);
}

int main() {  
  int capacity = 2;
  int weights[] = { 1, 1, 1 };
  int values[] = { 10, 20, 30 };
  int numberOfItems = 3;

  printf("%d\n", naiveKnapsackProblem(capacity, weights, values, numberOfItems - 1));
  printf("%d\n", dynamicProgrammingKnapsackProblem(capacity, weights, values, numberOfItems - 1));

  return 0;
}
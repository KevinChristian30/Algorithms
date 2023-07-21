#include <stdio.h>
#include <limits.h>

#define NUMBER_OF_NODES 4

int Graph[NUMBER_OF_NODES][NUMBER_OF_NODES] = {
  { 0, 10, 15, 20 },
  { 10, 0, 25, 25 }, 
  { 15, 25, 0, 30 },
  { 20, 25, 30, 0 }
};

int factorial(int n) {
  return n <= 1 ? n : n * factorial(n - 1);
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void generatePermutations(int permutations[][NUMBER_OF_NODES], int currentPermutation[NUMBER_OF_NODES], int currentIndex, int* permutationCount) {
  if (currentIndex == NUMBER_OF_NODES) {
    for (int i = 0; i < NUMBER_OF_NODES; i++) permutations[*permutationCount][i] = currentPermutation[i];

    *permutationCount = *permutationCount + 1;
  }

  for (int i = currentIndex; i < NUMBER_OF_NODES; i++) {
    swap(&currentPermutation[i], &currentPermutation[currentIndex]);

    generatePermutations(permutations, currentPermutation, currentIndex + 1, permutationCount);

    swap(&currentPermutation[i], &currentPermutation[currentIndex]);
  }
}

/**
 * Time Complexity O(n!)
 * Space Complexity O(n!) [Can be Improved to O(1)]
*/
int naiveTravelingSalesmanProblem() {
  int permutations[factorial(NUMBER_OF_NODES - 1)][NUMBER_OF_NODES];

  int currentPermutation[NUMBER_OF_NODES];
  for (int i = 0; i < NUMBER_OF_NODES; i++) currentPermutation[i] = i;

  int permutationCount = 0;

  generatePermutations(permutations, currentPermutation, 1, &permutationCount);

  int minimumCost = INT_MAX, currentCost;
  for (int i = 0; i < permutationCount; i++) {
    currentCost = 0;

    for (int j = 0; j < NUMBER_OF_NODES - 1; j++) 
      currentCost += Graph[permutations[i][j]][permutations[i][j + 1]];
  
    currentCost += Graph[permutations[i][NUMBER_OF_NODES - 1]][permutations[i][0]];

    if (currentCost < minimumCost) minimumCost = currentCost;
  }
  
  return minimumCost;
}

int memo[NUMBER_OF_NODES][1 << NUMBER_OF_NODES] = {0};
int solve(int posiiton, int mask) {
  if (mask == (1 << NUMBER_OF_NODES) - 1) return Graph[posiiton][0];
  
  if (memo[posiiton][mask] != -1) {
    puts("Memo");
    return memo[posiiton][mask];
  }
  
  int minimumCost = INT_MAX;
  for (int i = 0; i < NUMBER_OF_NODES; i++) {
    if ((mask & (1 << i)) == 0) {
      int cost = Graph[posiiton][i] + solve(i, mask | (1 << i));

      if (cost < minimumCost) minimumCost = cost;
    }
  }

  return memo[posiiton][mask] = minimumCost;
}

/**
 * Time Complexity O(n^2 * 2^n)
 * Space Complexity O(n * 2^n)
*/
int dynamicProgrammingTravelingSalesmanProblem() {
  for (int i = 0; i < NUMBER_OF_NODES; i++)
    for (int j = 0; j < (1 << NUMBER_OF_NODES); j++)
      memo[i][j] = -1;

  return solve(0, 1);
}

int main() {
  printf("%d\n", naiveTravelingSalesmanProblem());
  printf("%d\n", dynamicProgrammingTravelingSalesmanProblem());
  
  return 0;
}
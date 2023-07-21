#include <stdio.h>

/**
 * Time Complexity O(2^n)
 * Space Complexity O(1)
*/
int naiveCoinChange(int coins[], int toChange, int currentIndex) {
  if (toChange == 0) return 1;
  if (toChange < 0 || currentIndex  < 0) return 0;
  
  return naiveCoinChange(coins, toChange, currentIndex - 1) + 
         naiveCoinChange(coins, toChange - coins[currentIndex], currentIndex);
}

/**
 * Time Complexity O(toChange * number of coins)
 * Space Complexity O(toChange)
*/
int dynamicProgrammingCoinChange(int coins[], int toChange, int numberOfCoins) {
  int tab[toChange + 1] = {0};
  tab[0] = 1;

  for (int i = 0; i < numberOfCoins; i++)
    for (int j = 0; j <= toChange; j++)
      if (coins[i] <= j) tab[j] += tab[j - coins[i]];

  return tab[toChange];
}

int main() {
  int coins[] = { 1, 2, 3 };
  int numberOfCoins = 3;
  int toChange = 4;

  printf("%d\n", naiveCoinChange(coins, toChange, numberOfCoins - 1));
  printf("%d\n", dynamicProgrammingCoinChange(coins, toChange, numberOfCoins));

  return 0;
}
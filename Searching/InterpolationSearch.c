#include <stdio.h>

#define NOTFOUND -1

void printArray(int array[], int size){

    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    puts("");

}

int interpolationSearch(int array[], int size, int toSearch){

    int left = 0, right = size - 1;

    while (left <= right  && toSearch >= array[left] && toSearch <= array[right]){

        // b is the differance for each index step 
        int b = (array[right] - array[left]) / (right - left);
        int guess = left + (toSearch - array[left]) / b;

        if (array[guess] == toSearch) return guess;
        else if (array[guess] < toSearch) left = guess + 1;
        else right = guess - 1;

    }
    return NOTFOUND;

}

int main(){

    int N; scanf("%d", &N); getchar();
    
    int array[N + 1];
    for (int i = 0; i < N; i++){
        
        scanf("%d", &array[i]);
        getchar();

    }

    int toSearch; scanf("%d", &toSearch); getchar();
    
    int index = interpolationSearch(array, N, toSearch);

    printf("Array : "); printArray(array, N);
    
    if (index == NOTFOUND) printf("%d was not found!\n", toSearch);
    else printf("%d was found at index %d\n", toSearch, index);

    return 0;
}
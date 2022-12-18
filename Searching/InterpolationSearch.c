#include <stdio.h>

#define NOTFOUND -1

void printArray(int array[], int size){

    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    puts("");

}

int interpolationSearch(int array[], int size, int toSearch){

    int high = size - 1, low = 0;
    while (toSearch >= array[low] && toSearch <= array[high] && low <= high){

        int probe = low + (high - low) * (toSearch - array[low]) / (array[high] - array[low]);
        printf("Probe: %d\n", probe);

        if (array[probe] == toSearch) return probe;
        else if (array[probe] < toSearch) low = probe + 1;
        else high = probe + 1;

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
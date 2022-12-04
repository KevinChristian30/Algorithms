#include <stdio.h>

#define NOTFOUND -1

void printArray(int array[], int size){

    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    puts("");

}

int linearSearch(int array[], int size, int toSearch){

    for (int i = 0; i < size; i++) if (array[i] == toSearch) return i;
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
    
    int index = linearSearch(array, N, toSearch);

    printf("Array : "); printArray(array, N);
    
    if (index == NOTFOUND) printf("%d was not found!\n", toSearch);
    else printf("%d was found at index %d\n", toSearch, index);

    return 0;
}
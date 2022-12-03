#include <stdio.h>

void printArray(int array[], int size){

    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    puts("");

}

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

void selectionSort(int array[], int size){

    int minIndex;
    for (int i = 0; i < size - 1; i++){

        minIndex = i;
        for (int j = i + 1; j < size; j++) if (array[j] < array[minIndex]) minIndex = j;
        swap(&array[i], &array[minIndex]);

    }

}

int main(){

    int N; scanf("%d", &N); getchar();
    int array[N + 1];
    for (int i = 0; i < N; i++){
        scanf("%d", &array[i]);
        getchar();
    }

    printf("Unsorted Array: ");
    printArray(array, N);

    selectionSort(array, N);
    
    printf("Sorted Array: ");
    printArray(array, N);

    return 0;
}
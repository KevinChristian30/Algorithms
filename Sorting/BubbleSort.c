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

void bubbleSort(int array[], int size){

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1]) swap(&array[j], &array[j + 1]);

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

    bubbleSort(array, N);
    
    printf("Sorted Array: ");
    printArray(array, N);

    return 0;
}
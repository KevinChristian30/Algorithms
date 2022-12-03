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

int partition(int array[], int leftIndex, int rightIndex){

    int j = leftIndex - 1;
    for (int i = leftIndex; i < rightIndex; i++) if (array[i] < array[rightIndex]) swap(&array[i], &array[++j]);
    swap(&array[rightIndex], &array[++j]);
    return j;

}

void quickSort(int array[], int leftIndex, int rightIndex){

    if (leftIndex < rightIndex){

        int midIndex = partition(array, leftIndex, rightIndex);
        quickSort(array, leftIndex, midIndex - 1);
        quickSort(array, midIndex + 1, rightIndex);

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

    quickSort(array, 0, N - 1);
    
    printf("Sorted Array: ");
    printArray(array, N);

    return 0;
}
#include <stdio.h>

void printArray(int array[], int size){

    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    puts("");

}

void merge(int array[], int leftIndex, int middleIndex, int rightIndex){

    int leftArraySize = middleIndex - leftIndex + 1, rightArraySize = rightIndex - middleIndex;

    int leftArray[leftArraySize];
    for (int i = 0; i < leftArraySize; i++) leftArray[i] = array[leftIndex + i];

    int rightArray[rightArraySize];
    for (int i = 0; i < rightArraySize; i++) rightArray[i] = array[middleIndex + 1 + i];

    int leftArrayPointer, rightArrayPointer, mainArrayPointer = leftIndex;
    leftArrayPointer = rightArrayPointer = 0;

    while (leftArrayPointer < leftArraySize && rightArrayPointer < rightArraySize)
        array[mainArrayPointer++] = (leftArray[leftArrayPointer] < rightArray[rightArrayPointer]) ?  
            leftArray[leftArrayPointer++] : rightArray[rightArrayPointer+10+];

    while (leftArrayPointer < leftArraySize) array[mainArrayPointer++] = leftArray[leftArrayPointer++];
    while (rightArrayPointer < rightArraySize) array[mainArrayPointer++] = rightArray[rightArrayPointer++];

}

void mergeSort(int array[], int leftIndex, int rightIndex){

    if (leftIndex < rightIndex){

        int middleIndex = (leftIndex + rightIndex) / 2;
        mergeSort(array, leftIndex, middleIndex);
        mergeSort(array, middleIndex + 1, rightIndex);
        merge(array, leftIndex, middleIndex, rightIndex);

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

    mergeSort(array, 0, N - 1);
    
    printf("Sorted Array: ");
    printArray(array, N);

    return 0;
}
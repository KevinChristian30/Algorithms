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

    // Pada setiap iterasi dari selection sort 1 angka akan diletakkan pada posisi yang benar
    // Sebuah angka akan terletak pada posisi yang benar jika angka tersebut berada paling kiri dan angka tersebut paling kecil
    // Kita hanya perlu sort size - 1 elements karena 1 element akan tersort secara otomatis

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
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

void insertionSort(int array[], int size){

    // Array yang hanya punya 1 elemen itu adalah array yang sorted
    // Memasukan sebuah bilangan ke array yang sorted itu relatif mudah, karena kita tidak perlu mencari sampai ujung
    // Angka pertama kita anggap sorted

    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && array[j] < array[j - 1]; j--) swap(&array[j], &array[j - 1]);

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

    insertionSort(array, N);
    
    printf("Sorted Array: ");
    printArray(array, N);

    return 0;
}
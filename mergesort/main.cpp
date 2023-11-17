#include <iostream>
#include <ctime>
#include "MergeSort.h"

using namespace std;

int main()
{
    srand(time(NULL));
    
    int size = rand() % 10000 + 5;
    int* array;
    array = new int[size];

    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 10000 + 1;
    }

    MergeSort sort(size);
    sort.mergeSort(array, 0, size - 1);

    delete[] array;
}
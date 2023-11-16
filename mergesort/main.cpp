#include <iostream>
#include <ctime>
#include "MergeSort.h"

using namespace std;

int main()
{
    srand(time(NULL));
    
    int size = 10;
    int* array;
    array = new int[size];

    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1;
    }

    cout << "Tablica przed sortowaniem: " << endl;

    for (size_t i = 0; i < size; i++) {
        cout << array[i] << ", ";
    }
    
    cout << endl;

    MergeSort sort(size);

    sort.mergeSort(array, 0, size - 1);

    cout << "Tablica po sortowaniu: " << endl;

    for (size_t i = 0; i < size; i++) {
        cout << array[i] << ", ";
    }

    delete[] array;
}
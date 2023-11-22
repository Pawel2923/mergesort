#include <iostream>
#include <ctime>
#include "MergeSort.h"

using namespace std;

int main()
{
    srand(time(NULL));
    
    int size = rand() % 100 + 5;
    int* array;
    array = new int[size];

    for (size_t i = 0; i < size; i++) 
    {
        array[i] = rand() % 100 + 1;
    }

    cout << "Oryginalna tablica: " << endl;

    for (size_t i = 0; i < size; i++) 
    {
		cout << array[i] << " ";
	}

    MergeSort sort(size);
    sort.mergeSort(array, 0, size - 1);

    cout << "\nPosortowana tablica: " << endl;

    for (size_t i = 0; i < size; i++) 
    {
        cout << array[i] << " ";
    }

    delete[] array;
}
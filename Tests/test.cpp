#include <iostream>
#include <ctime>
#include "pch.h"
#include "..\mergesort\MergeSort.h"

static void mergeSort(int* array, int size)
{
    MergeSort sort(size);
    sort.mergeSort(array, 0, size - 1);
}

static TEST(MergeSortTest, ArrayChanged) {
    srand(time(NULL));

    int size = rand() % 10000 + 5;
    int* array;
    array = new int[size];
    int* arrayCopy;
    arrayCopy = new int[size];

    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 10000 + 1;
        arrayCopy[i] = array[i];
    }

    ASSERT_EQ(array, arrayCopy);

    delete[] array;
    delete[] arrayCopy;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
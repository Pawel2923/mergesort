#include <iostream>
#include <ctime>
#include "pch.h"
#include "MergeSort.h"

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

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10000 + 1;
    }

    for (int i = 0; i < size; i++) {
        arrayCopy[i] = array[i];
    }

    mergeSort(array, size);

    ASSERT_EQ(array, arrayCopy);

    delete[] array;
    delete[] arrayCopy;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
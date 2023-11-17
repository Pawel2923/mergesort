#include <iostream>
#include <ctime>
#include "pch.h"
#include "MergeSort.h"

static void mergeSort(int* array, int size, bool reverse = false)
{
    MergeSort sort(size);
    if (reverse)
    {
		sort.mergeSortReverse(array, 0, size - 1);
	}
    else
    {
		sort.mergeSort(array, 0, size - 1);
	}
}

static TEST(MergeSortTest, ArrayChanged) 
{
    srand(time(NULL));

    int size = rand() % 10000 + 5;
    int* array;
    array = new int[size];
    int* arrayCopy;
    arrayCopy = new int[size];

    for (size_t i = 0; i < size; i++) 
    {
        array[i] = rand() % 10000 + 1;
    }

    for (size_t i = 0; i < size; i++) 
    {
        arrayCopy[i] = array[i];
    }

    mergeSort(array, size);

    for (size_t i = 0; i < size; i++) 
    { 
        ASSERT_EQ(array[i], arrayCopy[i]);
    }

    delete[] array;
    delete[] arrayCopy;
}

static TEST(MegeSortTest, IsReverseSorted)
{
    srand(time(NULL));

    int size = rand() % 10000 + 5;
    int* array;
    array = new int[size];

    for (size_t i = 0; i < size; i++) 
    {
        array[i] = rand() % 10000 + 1;
    }

    mergeSort(array, size, true);

    ASSERT_TRUE(std::is_sorted(array, array + size, std::greater<int>()));

    delete[] array;
}

static TEST(MegeSortTest, RandomNumbers)
{
    srand(time(NULL));

    int size = rand() % 10000 + 5;
    int* array;
    array = new int[size];

    for (size_t i = 0; i < size; i++) 
    {
        array[i] = rand() % 10000 + 1;
    }

    mergeSort(array, size);

    ASSERT_TRUE(std::is_sorted(array, array + size));

    delete[] array;
}

static TEST(MegeSortTest, NegativeNumbers)
{
    srand(time(NULL));

    int size = rand() % 10000 + 5;
    int* array;
    array = new int[size];

    for (size_t i = 0; i < size; i++) 
    {
        array[i] = (rand() % 10000 + 1) * (-1);
    }

    mergeSort(array, size);

    ASSERT_TRUE(std::is_sorted(array, array + size));

    delete[] array;
}

static TEST(MergeSortTest, NegAndPosNumbers)
{
    srand(time(NULL));

    int size = rand() % 10000 + 5;
    int* array;
    array = new int[size];

    for (size_t i = 0; i < size; i++) 
    {
        array[i] = (rand() % 10000 + 1) * (-1) + (rand() % 10000 + 1);
    }

    mergeSort(array, size);

    ASSERT_TRUE(std::is_sorted(array, array + size));

    delete[] array;
}

static TEST(MergeSortTest, EmptyArray)
{
    int size = 0;
    int* array;
    array = new int[size];

    ASSERT_NO_THROW(mergeSort(array, size));

    delete[] array;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
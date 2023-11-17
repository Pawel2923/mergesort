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

static TEST(MergeSortTest, OneElementArrayChanged)
{
    srand(time(NULL));

    int size = 1;
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

static TEST(MergeSortTest, DuplicateNumbers)
{
    int array[] = { 6, 44, 44, 22, 22, 11, 55, 1, 11, 2, 6, 7};

    mergeSort(array, 12);

    ASSERT_TRUE(std::is_sorted(array, array + 12));
}

static TEST(MergeSortTest, DuplicateNegNumbers)
{
    int array[] = { -6, -44, -44, -22, -22, -11, -55, -1, -11, -2, -6, -7 };

    mergeSort(array, 12);

    ASSERT_TRUE(std::is_sorted(array, array + 12));
}

static TEST(MergeSortTest, DuplicateNegAndPosNumbers)
{
    int array[] = { 6, -44, 44, 22, 22, -11, 55, -1, -11, -2, 6, -7 };

    mergeSort(array, 12);

    ASSERT_TRUE(std::is_sorted(array, array + 12));
}

static TEST(MergeSortTest, TwoElements)
{
    int array[] = { 5555555, 22446 };

    mergeSort(array, 2);

    ASSERT_TRUE(std::is_sorted(array, array + 2));
}

static TEST(MergeSortTest, LargeArray)
{
    srand(time(NULL));

    int size = 500000;
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

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
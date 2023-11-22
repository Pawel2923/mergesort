#include <iostream>
#include <ctime>
#include "pch.h"
#include "MergeSort.h"

static void mergeSort(int* array, int size)
{
    MergeSort sort(size);
    sort.mergeSort(array, 0, size - 1);
}

static TEST(MergeSortTest, ArrayChanged)
{
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arrayCopy[10] = { 0 };

    for (size_t i = 0; i < 10; i++)
    {
        arrayCopy[i] = array[i];
    }

    mergeSort(array, 10);

    for (size_t i = 0; i < 10; i++)
    {
        ASSERT_EQ(array[i], arrayCopy[i]);
    }
}

static TEST(MergeSortTest, IsReverseSorted)
{
    int array[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int arrayCopy[10] = { 0 };

    for (size_t i = 0; i < 10; i++)
    {
        arrayCopy[i] = array[i];
    }

    mergeSort(array, 10);

    ASSERT_TRUE(std::is_sorted(array, array + 10));
}

static TEST(MergeSortTest, RandomNumbers)
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

static TEST(MergeSortTest, NegativeNumbers)
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
    int array[] = { 1 };
    int arrayCopy[1] = { 0 };
    arrayCopy[0] = array[0];

    mergeSort(array, 1);

    for (size_t i = 0; i < 1; i++)
    {
        ASSERT_EQ(array[i], arrayCopy[i]);
    }
}

static TEST(MergeSortTest, DuplicateNumbers)
{
    int array[] = { 6, 44, 44, 22, 22, 11, 55, 1, 11, 2, 6, 7 };

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

static TEST(MergeSortTest, LargeArrayDuplicates)
{
    srand(time(NULL));

    int size = 500000;
    int* array;
    array = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        array[i] = (rand() % 1000 + 1) * (-1) + (rand() % 1000 + 1);
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
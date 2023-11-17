#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort
{
private:
    int* tempArray;
    void reverseArray(int* arr, unsigned left, unsigned right);
    void merge(int* arr, unsigned left, unsigned center, unsigned right);

public:
    MergeSort(int size) : tempArray(new int[size]) {}
    ~MergeSort() { delete[] tempArray; }
    void mergeSort(int* arr, unsigned left, unsigned right);
    void mergeSortReverse(int* arr, unsigned left, unsigned right);
};

#endif // !MERGESORT_H
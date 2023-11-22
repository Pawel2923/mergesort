#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort
{
private:
    int* tempArray;
    void merge(int* arr, unsigned left, unsigned center, unsigned right);

public:
    MergeSort(int size) : tempArray(size > 0 ? new int[size] : nullptr) {}
    ~MergeSort() { delete[] tempArray; }
    void mergeSort(int* arr, unsigned left, unsigned right);
};

#endif // !MERGESORT_H
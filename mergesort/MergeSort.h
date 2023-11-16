#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort
{
private:
    int* tempArray;

public:
    MergeSort() : tempArray(nullptr) {}
    ~MergeSort() { delete[] tempArray; }
    void merge(int* arr, unsigned left, unsigned center, unsigned right);
    void mergeSort(int* arr, unsigned left, unsigned right);
};

#endif // !MERGESORT_H
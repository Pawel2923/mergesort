#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H
#include "list.h";

class MergeSort
{
private:
    List* list;
    unsigned center;

public:
    MergeSort(List* list);
    ~MergeSort();
    void sort();
    void merge(unsigned left, unsigned center, unsigned right);
    void mergeSort(unsigned left, unsigned right);
};

#endif // !MERGESORT_H
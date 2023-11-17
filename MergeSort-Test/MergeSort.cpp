#include "pch.h"
#include "MergeSort.h"

void MergeSort::reverseArray(int* arr, unsigned left, unsigned right)
{
	int temp;

	while (left < right)
	{
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}

void MergeSort::merge(int* arr, unsigned left, unsigned center, unsigned right)
{
	int i, j;

	for (i = center + 1; i > left; i--)
	{
		tempArray[i - 1] = arr[i - 1];
	}

	for (j = center; j < right; j++)
	{
		tempArray[right + center - j] = arr[j + 1];
	}

	for (size_t k = left; k <= right; k++)
	{
		if (tempArray[j] < tempArray[i])
		{
			arr[k] = tempArray[j--];
		}
		else
		{
			arr[k] = tempArray[i++];
		}
	}
}

void MergeSort::mergeSort(int* arr, unsigned left, unsigned right)
{
	if (left >= right) 
	{
		return;
	}

	unsigned center = (left + right) / 2;

	mergeSort(arr, left, center);
	mergeSort(arr, center + 1, right);

	merge(arr, left, center, right);
}

void MergeSort::mergeSortReverse(int* arr, unsigned left, unsigned right)
{
	mergeSort(arr, left, right);
	reverseArray(arr, left, right);
}
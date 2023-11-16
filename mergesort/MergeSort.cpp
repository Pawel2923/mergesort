#include "MergeSort.h"

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

	for (int k = left; k <= right; k++) 
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
	if (left >= right) {
		return;
	}

	unsigned center = (left + right) / 2;

	mergeSort(arr, left, center);
	mergeSort(arr, center + 1, right);

	merge(arr, left, center, right);
}
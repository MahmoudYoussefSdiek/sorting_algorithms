#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted array
 *
 * @array: The array to be sorted
 * @left: The left subarray
 * @left_size: The size of the left subarray
 * @right: The right subarray
 * @right_size: The size of the right subarray
 *
 * Return: Nothing
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		size_t left_size = mid;
		size_t right_size = size - mid;
		int *left = array;
		int *right = array + mid;

		printf("Merging...\n");
		printf("[left]: ");
		print_array(left, left_size);
		printf("[right]: ");
		print_array(right, right_size);

		merge_sort(left, left_size);
		merge_sort(right, right_size);

		printf("[Done]: ");
		merge(array, left, left_size, right, right_size);
		print_array(array, size);
	}
}

#include "sort.h"

/**
 * shell_sort- function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j;
	int i;
	int temp;

	for (gap = 1; gap < size / 3;)
		gap = gap * 3  + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i + gap] > array[i])
					break;
				else if (!(array[i + gap] > array[i]))
				{
					temp = array[i +  gap];
					array[i + gap] = array[i];
					array[i] = temp;
				}
			}
		}
		print_array(array, size);
	}
}

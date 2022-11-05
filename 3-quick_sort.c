#include "sort.h"

/**
 * partition_array - function that partitions a
 * given array on a pivot implementing lomuto scheme
 * @array: given array to be sorted
 * @size: size of areay
 * @head: starting index of array
 * @tail: ending index of array
 * Return: index of partition
 */
int partition_array(int *array, size_t size, int head, int tail)
{
	int i, j, piv, temp;

	piv = array[head];
	i = head;
	j = tail;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] <= piv);
		do {
			j--;
		} while (array[j] > piv);
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	if (array[head] > array[j])
	{
		temp = array[head];
		array[head] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
	return (j);
}
/**
 * lomuto_sort - function that implements lomuto sort recursively
 * @array: given array to be sorted
 * @size: size of areay
 * @head: starting index of array
 * @tail: ending index of array
 * Return: nothing
 */
void lomuto_sort(int *array, size_t size, int head, int tail)
{
	int pivot;

	if (head < tail)
	{
		pivot = partition_array(array, size, head, tail);
		lomuto_sort(array, size, head, pivot);
		lomuto_sort(array, size, pivot + 1, tail);
	}
}
/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size);
}

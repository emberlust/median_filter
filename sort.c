#include "sort.h"
#include <stdlib.h>

void merge_sort(int* vector, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		merge_sort(vector, left, middle);
		merge_sort(vector, middle + 1 , right);
		merge(vector, left, middle, right);
	}
}

void merge(int* vector, int left, int middle, int right)
{

	int i;
	int j;
	int k;

	int* vect1 = calloc(middle - left + 1, sizeof(int));
	int* vect2 = calloc(right - middle + 1, sizeof(int));

	for (i = 0; i < middle - left + 1; i++)
	{
		vect1[i] = vector[left + i];
	}

	for (j = 0; j < right - middle; j++)
	{
		vect2[j] = vector[middle + 1 + j];
	}

	i = 0;
	j = 0;
	k = 0;

	while (i < (middle - left + 1) && (j < right - middle ))
	{
		if (vect1[i] < vect2[j])
		{
			vector[left + k++] = vect1[i++];
		}
		else
		{
			vector[left + k++] = vect2[j++];
		}
	}

	while (i < middle - left + 1)
	{
		vector[left + k++] = vect1[i++];
	}

	while (j < right - middle )
	{
		vector[left + k++] = vect2[j++];
	}

	free(vect1);
	free(vect2);
}

void swap(int* add1, int* add2)
{
	int* new_add;
	new_add = add1;
	add1 = add2;
	add2 = add1;
}

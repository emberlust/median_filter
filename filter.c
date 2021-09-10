#include "filter.h"
#include "sort.h"
#include <stdlib.h>

int* create_array(int* matrix, int range, int x, int y, int width, int height)
{
	int* vector = malloc(range * range * sizeof(int));
	int k = 0;

	for (int i = 0; i < range; i++)
	{
		for (int j = 0; j < range; j++)
		{
			int cx, cy;

			if (x - i < 0)
			{
				cx = 0;
			}
			else
			{
				if (x - i > height - 1)
				{
					cx = height - 1;
				}
				else
				{
					cx = x - i;
				}
			}

			if (y - j < 0)
			{
				cy = 0;
			}
			else
			{
				if (y - j > width - 1)
				{
					cy = width - 1;
				}
				else
				{
					cy = y - j;
				}
			}

			vector[k++] = matrix[cx * width + cy];
		}
	}

	return vector;
}

void filter(pgmData* myPGM, int range)
{
	int* new_matrix = malloc(myPGM->width * myPGM->height * sizeof(int));

	for (int i = 0; i < myPGM->height;i++)
	{
		for (int j = 0; j < myPGM->width; j++)
		{
			int* vector  = create_array(myPGM->value_matrix, range, i, j, myPGM->width, myPGM->height);
			merge_sort(vector, 0, range * range - 1);
			new_matrix[i * myPGM->width + j] = vector[range * range / 2];
			free(vector);
		}
	}

	int* swap;
	swap = myPGM->value_matrix;
	myPGM->value_matrix = new_matrix;
	new_matrix = swap;
	free(new_matrix);
}
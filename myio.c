#include <stdio.h>
#include <stdlib.h>
#include "myio.h"
#include "PGM.h"

void input(pgmData* myPGM, FILE* stream)
{
	fscanf_s(stream, "%s", myPGM->fileType, 3);
	fscanf_s(stream, "%d", &myPGM->width);
	fscanf_s(stream, "%d", &myPGM->height);
	fscanf_s(stream, "%d", &myPGM->max_white);

	myPGM->value_matrix = calloc(myPGM->width * myPGM->height, sizeof(int));

	for (int iterator = 0; iterator < myPGM->width * myPGM->height; iterator++)
	{
		fscanf_s(stream, "%d", &myPGM->value_matrix[iterator]);
	}

}

void output(pgmData* myPGM, FILE* stream)
{
	fprintf_s(stream, "%s\n", myPGM->fileType);
	fprintf_s(stream, "%d ", myPGM->width);
	fprintf_s(stream, "%d\n", myPGM->height);
	fprintf_s(stream, "%d\n", myPGM->max_white);

	for (int i = 0; i < myPGM->height; i++)
	{
		for (int j = 0; j < myPGM->width; j++)
		{
			fprintf_s(stream, "%d ", myPGM->value_matrix[i * myPGM->width + j]);
		}
		fprintf_s(stream, "\n");
	}
}
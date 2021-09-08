#include <stdio.h>
#include <stdlib.h>
#include "myio.h"
#include "PMG.h"

void input(pmgData* myPGM, FILE* stream)
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
#include <stdio.h>
#include <stdlib.h>
#include "myio.h"
#include "PGM.h"
#include "sort.h"
#include "filter.h"

int main()
{
	FILE* stream;
	pgmData* myPGM;

	myPGM = malloc(sizeof(pgmData));
	myPGM->fileType = malloc(3 * sizeof(char));

	fopen_s(&stream, "test.txt", "r");
	input(myPGM, stream);
	filter(myPGM, 3);

	fclose(stream);

	fopen_s(&stream, "test.txt", "w");
	output(myPGM, stream);



	free(myPGM->value_matrix);
	free(myPGM->fileType);
	free(myPGM);

	fclose(stream);

	return 0;
}
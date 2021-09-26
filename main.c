#include <stdio.h>
#include <stdlib.h>
#include "myio.h"
#include "PGM.h"
#include "sort.h"
#include "filter.h"

int main()
{
	char file_name[100];

	FILE* stream;
	pgmData* myPGM;

	myPGM = malloc(sizeof(pgmData));
	myPGM->fileType = malloc(3 * sizeof(char));

	scanf_s("%s", file_name);

	fopen_s(&stream, file_name, "r");
	input(myPGM, stream);
	filter(myPGM, 3);

	fclose(stream);

	fopen_s(&stream, "output.pgm", "w");
	output(myPGM, stream);



	free(myPGM->value_matrix);
	free(myPGM->fileType);
	free(myPGM);

	fclose(stream);

	return 0;
}
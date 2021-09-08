#include <stdio.h>
#include <stdlib.h>
#include "myio.h"
#include "PGM.h"
#include "sort.h"

int main()
{
	FILE* stream;
	pgmData* myPGM;

	myPGM = malloc(sizeof(pgmData));
	myPGM->fileType = malloc(3 * sizeof(char));

	fopen_s(&stream, "test.txt", "r");
	input(myPGM, stream);

	fclose(stream);

	return 0;
}
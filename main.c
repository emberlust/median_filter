#include <stdio.h>
#include <stdlib.h>
#include "myio.h"
#include "PMG.h"
#include "sort.h"

int main()
{
	FILE* stream;
	pmgData* myPMG;

	myPMG = malloc(sizeof(pmgData));
	myPMG->fileType = malloc(3 * sizeof(char));

	fopen_s(&stream, "test.txt", "r");
	input(myPMG, stream);

	fclose(stream);

	return 0;
}
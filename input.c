#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input(char* fileType, int* width, int* height, int* maxVal, FILE* stream)
{

	char* buffer[100];
	
	fscanf_s(stream, "%c[^\n]", buffer);
	if (buffer[0] != '#')
	{
		strcpy_s(fileType, 3, buffer);
	}

}
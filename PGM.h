#ifndef _PGM_H
#define _PGM_H

typedef struct pgmData{
	char* fileType;   //pgm file type
	int width;        //image width 
	int height;       //image height 
	int max_white;    //image max white value 
	int* value_matrix; //value table 
} pgmData;

#endif
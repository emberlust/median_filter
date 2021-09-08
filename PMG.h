#ifndef _PMG_H
#define _PMG_H

typedef struct pmgData{
	char* fileType;   //pmg file type
	int width;        //image width 
	int height;       //image height 
	int max_white;    //image max white value 
	int* value_matrix; //value table 
} pmgData;

#endif
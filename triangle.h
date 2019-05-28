#ifndef TRIANGLE_H
#define TRIANGLE_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>

	typedef struct{
		float a;
		float b;
		float c;
	} Triangle;

	Triangle* readData(char *nomDeFichier);
	int typeTriangle(float a, float b, float c);

#endif
#include "triangle.h"
#define MAX(a,b) (((a)>(b))?(a):(b))

/**
*@author : Barbaria Gaëtan.
*@author : Perrot Gaëtan.
*/

Triangle* readData(char *nomDeFichier){
	float c1, c2, c3;
	Triangle *triangle = malloc(sizeof(Triangle));
	FILE *fichier = fopen(nomDeFichier, "r");

	if(fichier == NULL){
		triangle->a = -1;
		triangle->b = -1;
		triangle->c = -1;
	}else{
		int res = fscanf(fichier, "%f,%f,%f", &c1, &c2, &c3);
	
		if(res != 3){
			triangle->a = -1;
			triangle->b = -1;
			triangle->c = -1;
		}else{
			triangle->a = c1;
			triangle->b = c2;
			triangle->c = c3;
		}
	}

	fclose(fichier);
	return triangle;
}

int typeTriangle(float a, float b, float c){

	if( a <= 0 || b <= 0 || c <= 0 ){
		return -1;
	}

	if(a == b && b == c){
		return 3;
	}else if(a == b || b == c || a == c ){
		return 2;
	}else {
		//La somme des 2 plus petit est > au plus grand 
		int max = 0, c1 = 0, c2 = 0;

		max = MAX(a, b);

		if(max == a){
			c1 = b;
			max = MAX(max, c);
			if(max == c){
				c2 = a;
			}else {
				c2 = c;
			}
		}else {
			c1 = a;
			max = MAX(max, c);
			if(max == c){
				c2 = b;
			}else {
				c2 = c;
			}
		}

		if(max < c1 + c2){
			return 1;
		}

		return -1;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

int main(int argc, char* argv[]){

	if(argc-1 != 1){
		printf("Usage : %s nomFichier\n", argv[0]);
		exit(1);
	}

	Triangle *triangle = readData(argv[1]);
	int res = typeTriangle(triangle->a, triangle->b, triangle->c);

	switch(res){
		case -1:
			printf("Ce n'est pas un triangle.\n");
			break;
		case 1:
			printf("C'est un triangle quelconque.\n");
			break;
		case 2:
			printf("C'est un triangle isocèle.\n");
			break;
		case 3:
			printf("C'est un triangle équilatéral.\n");
			break;
	}

	free(triangle);

	return 0;
}
#include "../include/compiler.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){


	int* a = NULL;
	int b = 10;

	a = &b;

	printf("%d\n", *a);
}

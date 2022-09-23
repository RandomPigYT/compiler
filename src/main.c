#include "../include/compiler.h"
#include "../include/globals.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

	for(int i = 0; i < sizeof(separators); i++){

		printf("%c\n", separators[i]);
	}
	
}

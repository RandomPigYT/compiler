#include "../../include/compiler.h"
#include "../../include/util.h"
#include "../../include/globals.h"
#include <stdint.h>
#include <stdbool.h>


bool isSep(char ch){


	for(uint32_t i = 0; i < sizeof(separators); i++){
		
		if(ch == separators[i]) return true;
	}

	return false;
}


uint64_t tokenize(char* src, char*** dest){
	
	uint64_t length = 0;

	char* buf = NULL;
	Memory bufMem = {.memory = 0, .size = 0};
	Memory destMem = {.size = 0, .memory = 0};
	

	
	
	return length;
}


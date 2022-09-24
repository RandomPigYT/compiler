#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/compiler.h"
#include "../../include/globals.h"
#include "../../include/util.h"

bool isSep(char ch) {
  for (uint32_t i = 0; i < sizeof(separators); i++) {
    if (ch == separators[i]) return true;
  }

  return false;
}

void terminateStr(char* str, Memory* mem) {
  expandArray(str, (*mem), char);

  str[mem->size] = 0;

  mem->size++;
  mem->memory--;
}

uint64_t tokenize(char* src, char*** dest) {
  uint64_t length = 0;

  char* buf = NULL;
  Memory bufMem = {.memory = 0, .size = 0};
  Memory destMem = {.size = 0, .memory = 0};

  char* temp = src;

  while (*temp) {
		
		// TODO: Fix the bloody function

    temp++;
  }


  return length + 1;
}

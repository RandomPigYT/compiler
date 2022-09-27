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

char* insertSpace(char* src) {
  char* temp = src;

  // Find the number of separators
  uint64_t count = 0;
  while (*temp) {
    if (isSep(*temp)) count++;

    temp++;
  }

  src = realloc(src, 2 * (strlen(src) + 1 + count));

  temp = src;

  while (*temp) {
    if (isSep(*temp)) {
      memmove(temp + 1, temp, strlen(temp) + 1);
      *temp = ' ';

      temp++;

      memmove(temp + 2, temp + 1, strlen(temp + 1) + 1);
      *(temp + 1) = ' ';
    }

    temp++;
  }

  return src;
}

char** tokenize(char* src, char** dest, uint64_t* len) {
  char* buf = NULL;
  Memory bufMem = {.memory = 0, .size = 0};
  Memory destMem = {.size = 0, .memory = 0};

  char* temp = malloc(strlen(src) + 1);
  strcpy(temp, src);

  temp = insertSpace(temp);
  src = temp;

  while (*temp) {
    if (*temp != ' ') {
      expandArray(buf, bufMem, char);

      buf[bufMem.size] = *temp;

      bufMem.size++;
      bufMem.memory--;

    }

    else if (*temp == ' ' && *(temp + 1) != ' ') {
      terminateStr(buf, &bufMem);

      expandArray(dest, destMem, char*);

      dest[destMem.size] = buf;
      destMem.size++;
      destMem.memory--;

      buf = NULL;
      bufMem.size = 0;
      bufMem.memory = 0;
    }

    temp++;
  }

  if (buf != NULL) {
    terminateStr(buf, &bufMem);
    expandArray(dest, destMem, char*);

    dest[destMem.size] = buf;

		destMem.size++;
		destMem.memory--;

  }

  free(src);

	*len = destMem.size;
  return dest;
}

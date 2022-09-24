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
    if (isSep(*temp)) {
      if (buf) {
        terminateStr(buf, &bufMem);
        expandArray((*dest), destMem, char*);

        // Add character
        (*dest)[destMem.size] = buf;

        destMem.memory--;
        destMem.size++;

        length++;
      }

      expandArray((*dest), destMem, char*);

      // Add separator
      char* s = malloc(2);
      s[0] = *temp;
      s[1] = 0;

      (*dest)[destMem.size] = s;

      destMem.size++;
      destMem.memory--;

      // Reset buf

      buf = NULL;

      bufMem.size = 0;
      bufMem.memory = 0;

      length++;
    }

    else if (*temp == ' ') {
      if (buf) {
        terminateStr(buf, &bufMem);
        expandArray((*dest), destMem, char*);

        // Add character
        (*dest)[destMem.size] = buf;

        destMem.memory--;
        destMem.size++;

        // Reset buf
        buf = NULL;

        bufMem.size = 0;
        bufMem.memory = 0;

        length++;
      }
    }

    else {
      expandArray(buf, bufMem, char);

      buf[bufMem.size] = *temp;

      bufMem.size++;
      bufMem.memory--;
    }

    temp++;
  }

    terminateStr(buf, &bufMem);
    expandArray((*dest), destMem, char*);

    (*dest)[destMem.size] = buf;

  return length + 1;
}

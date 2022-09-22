#ifndef COMPILER_UTIL_H
#define	COMPILER_UTIL_H

#include <stddef.h>

#define expandArray(array, mem, type){  \
  if (mem.size == 0){  \
\
    array = malloc(10 * sizeof(type));  \
    mem.memory = 10;  \
  } \
\
  else if (mem.memory == 0){ \
\
    array = realloc(array, (2 * mem.size) * sizeof(type)); \
\
    mem.memory = 2 * mem.size;  \
  } \
}


typedef struct{
	
  size_t size;
  size_t memory;

} Memory;

#endif

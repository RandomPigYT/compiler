#include <stdio.h>
#include <stdlib.h>

#include "../include/compiler.h"
#include "../include/globals.h"

int main(int argc, char** argv) {
  if (argc <= 1) {
    fprintf(stderr,
            "\033[0;31mfatal error\033[0m: no input files\ncompilation "
            "terminated.\n");

    return EXIT_FAILURE;
  }

  char** dest = NULL;

  int count = tokenize(argv[1], &dest);

  for (int i = 0; i < count; i++) {
    printf("\"%s\" ", dest[i]);
  }

  printf("\n");

  return 0;
}

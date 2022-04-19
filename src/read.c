#include <stdlib.h>
#include <stdio.h>

#include "def.h"

char *read_input() {
  int buffer_size = INPUT_BUFFER_SIZE;
  char *buffer = malloc(sizeof(char) * buffer_size);
  int ch, index = 0;

  if (!buffer) {
    fprintf(stderr, "bob: memory allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    ch = getchar();

    if (ch == EOF || ch == '\n') {
      buffer[index] = '\0';
      return buffer;
    } else {
      buffer[index] = ch;
    }
    index++;

    if (index >= buffer_size) {
      buffer_size += INPUT_BUFFER_SIZE;
      buffer = realloc(buffer, sizeof(char) * buffer_size);
      if (!buffer) {
        fprintf(stderr, "bob: memory allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
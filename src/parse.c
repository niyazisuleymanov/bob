#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/def.h"

char **parse(char *line) {
  int buffer_size = TOKEN_BUFFER_SIZE;
  char **tokens = malloc(sizeof(char*) * buffer_size);
  char *token;
  int index = 0;

  token = strtok(line, TOKEN_DELIM);
  while (token != NULL) {
    tokens[index] = token;
    index++;

    if (index >= buffer_size) {
      buffer_size += TOKEN_BUFFER_SIZE;
      tokens = realloc(tokens, sizeof(char*) * buffer_size);
      if (!tokens) {
        fprintf(stderr, "bob: memory allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, TOKEN_DELIM);
  }

  tokens[index] = NULL;
  return tokens;
}
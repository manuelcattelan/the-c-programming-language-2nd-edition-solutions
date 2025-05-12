#include <stdio.h>
#include <stdlib.h>

#define MIN_LINE_LENGTH 80
#define MAX_LINE_LENGTH 1000

int get_line(char line[], int max_line_length);

int main() {
  int line_length = 0;
  char line[MAX_LINE_LENGTH];
  while ((line_length = get_line(line, MAX_LINE_LENGTH)) > -1)
    if (line_length > MIN_LINE_LENGTH)
      printf("%s\n", line);
  printf("\n");
  return EXIT_SUCCESS;
}

int get_line(char line[], int max_line_length) {
  int character, i;
  for (i = 0; i < max_line_length - 1 && (character = getchar()) != EOF &&
              character != '\n';
       i++)
    line[i] = character;
  line[i] = '\0';
  if (character == EOF && i == 0)
    return -1;
  return i;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

int get_line(char line[], int max_line_length);
int strip_line(char line[], int line_length);
void copy_line(char from[], char to[]);

int main() {
  int line_length = 0;
  char line[MAX_LINE_LENGTH];
  while ((line_length = get_line(line, MAX_LINE_LENGTH)) > -1) {
    line_length = strip_line(line, line_length);
    if (line_length > 0)
      printf("%s\n", line);
  }
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

void copy_line(char from[], char to[]) {
  int i;
  for (i = 0; (to[i] = from[i]) != '\0'; i++)
    ;
}

int strip_line(char line[], int line_length) {
  int i, new_line_length;
  char new_line[MAX_LINE_LENGTH];
  for (i = new_line_length = 0; i < line_length && line[i]; i++) {
    if (new_line_length != 0 ||
        (new_line_length == 0 && line[i] != ' ' && line[i] != '\t'))
      new_line[new_line_length++] = line[i];
  }
  new_line[new_line_length] = '\0';
  copy_line(new_line, line);
  return new_line_length;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

int get_line(char line[], int max_line_length);
void copy_line(char from[], char to[]);
void reverse(char line[]);

int main() {
  int line_length = 0;
  char line[MAX_LINE_LENGTH];
  while ((line_length = get_line(line, MAX_LINE_LENGTH)) > -1) {
    if (line_length > 1)
      reverse(line);
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

void reverse(char line[]) {
  int i, j;
  char line_reversed[MAX_LINE_LENGTH];
  for (i = 0; line[i] != '\0'; i++)
    ;
  --i;
  for (j = 0; i >= 0; i--)
    line_reversed[j++] = line[i];
  line[j] = '\0';
  copy_line(line_reversed, line);
}

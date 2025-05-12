#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

int get_line(char line[], int max_line_length);
void copy_line(char from[], char to[]);

int main() {
  int line_length, max_line_length;
  char line[MAX_LINE_LENGTH];
  char longest_line[MAX_LINE_LENGTH];
  line_length = max_line_length = 0;
  while ((line_length = get_line(line, MAX_LINE_LENGTH)) > -1) {
    if (line_length > max_line_length) {
      max_line_length = line_length;
      copy_line(line, longest_line);
    }
  }
  printf("\n");
  if (max_line_length > 0)
    printf("%d: %s\n", max_line_length, longest_line);
  return EXIT_SUCCESS;
}

int get_line(char line[], int max_line_length) {
  int character, i, line_length;
  for (i = line_length = 0; (character = getchar()) != EOF && character != '\n';
       i++)
    if (i < max_line_length - 1)
      line[line_length++] = character;
  line[line_length] = '\0';
  if (character == EOF && line_length == 0)
    return -1;
  return i;
}

void copy_line(char from[], char to[]) {
  int i;
  for (i = 0; (to[i] = from[i]) != '\0'; i++)
    ;
}

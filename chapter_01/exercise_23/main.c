#include <stdio.h>

#define INSIDE_ESCAPE_SEQUENCE 3
#define OUTSIDE_ESCAPE_SEQUENCE 2
#define INSIDE_STRING 1
#define OUTSIDE_STRING 0

int main() {
  int character, last_seen_character, escape_sequence_status, string_status;
  escape_sequence_status = OUTSIDE_ESCAPE_SEQUENCE;
  string_status = OUTSIDE_STRING;
  while ((character = getchar()) != EOF) {
    if (character == '\'') {
      if (escape_sequence_status == OUTSIDE_ESCAPE_SEQUENCE)
        escape_sequence_status = INSIDE_ESCAPE_SEQUENCE;
      else
        escape_sequence_status = OUTSIDE_ESCAPE_SEQUENCE;
      putchar(character);
    } else if (character == '"') {
      if (string_status == OUTSIDE_STRING)
        string_status = INSIDE_STRING;
      else
        string_status = OUTSIDE_STRING;
      putchar(character);
    } else if (character == '/' &&
               escape_sequence_status == OUTSIDE_ESCAPE_SEQUENCE &&
               string_status == OUTSIDE_STRING) {
      character = getchar();
      if (character == '*') {
        while ((character = getchar()) != '*')
          ;
        character = getchar();
        if (character == '/')
          character = EOF;
        else
          while ((character = getchar()) != '/')
            ;
      } else if (character == '/') {
        while ((character = getchar()) != EOF && character != '\n')
          ;
        putchar(character);
      }
    } else
      putchar(character);
    last_seen_character = character;
  }
  printf("\n");
}

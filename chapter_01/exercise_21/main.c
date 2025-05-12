#include <stdio.h>

#define TABSTOPS 8

int main() {
  int character, character_count, blank_count;
  character_count = blank_count = 0;
  while ((character = getchar()) != EOF) {
    if (character == ' ') {
      ++character_count;
      ++blank_count;
      if (character_count == TABSTOPS) {
        putchar('\t');
        character_count = blank_count = 0;
      }
    } else {
      if (blank_count > 0)
        for (int i = 0; i < blank_count; i++)
          putchar(' ');
      putchar(character);
      blank_count = 0;
      if (character == '\n')
        character_count = 0;
      else {
        ++character_count;
        if (character_count == TABSTOPS)
          character_count = 0;
      }
    }
  }
  printf("\n");
}

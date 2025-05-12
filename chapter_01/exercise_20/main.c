#include <stdio.h>

#define TABSTOPS 8

int main() {
  int character, character_count;
  character_count = 0;
  while ((character = getchar()) != EOF) {
    if (character == '\t') {
      for (int i = 0; i < TABSTOPS - character_count; i++)
        putchar(' ');
      character_count = 0;
    } else {
      putchar(character);
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

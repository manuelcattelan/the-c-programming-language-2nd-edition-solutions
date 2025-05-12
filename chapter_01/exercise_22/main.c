#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int main() {
  int character, character_count, blank_count;
  character_count = blank_count = 0;
  while ((character = getchar()) != EOF) {
    if (character == '\n') {
      putchar(character);
      character_count = blank_count = 0;
    } else {
      if (character == ' ') {
        ++character_count;
        ++blank_count;
      } else {
        if (blank_count > 0 && character_count < MAX_LINE_LENGTH)
          for (int i = 0; i < blank_count; i++)
            putchar(' ');
        blank_count = 0;
        if (character_count >= MAX_LINE_LENGTH) {
          putchar('\n');
          character_count = blank_count = 0;
        }
        putchar(character);
        ++character_count;
      }
    }
  }
  printf("\n");
}

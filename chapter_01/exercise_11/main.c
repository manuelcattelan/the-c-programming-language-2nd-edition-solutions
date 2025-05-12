#include <stdio.h>

#define INSIDE_WORD 1
#define OUTSIDE_WORD 0

int main() {
  int character, newline_count, word_count, character_count, word_status;
  word_status = OUTSIDE_WORD;
  newline_count = word_count = character_count = 0;
  while ((character = getchar()) != EOF) {
    ++character_count;
    if (character == '\n')
      ++newline_count;
    if (character == ' ' || character == '\t' || character == '\n') {
      word_status = OUTSIDE_WORD;
    } else if (word_status == OUTSIDE_WORD) {
      word_status = INSIDE_WORD;
      ++word_count;
    }
  }
  printf("%d %d %d\n", newline_count, word_count, character_count);
}

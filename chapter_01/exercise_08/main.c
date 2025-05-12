#include <stdio.h>

int main() {
  int character, blank_count, tab_count, newline_count;
  blank_count = tab_count = newline_count = 0;
  while ((character = getchar()) != EOF) {
    if (character == ' ')
      ++blank_count;
    if (character == '\t')
      ++tab_count;
    if (character == '\n')
      ++newline_count;
  }
  printf("\n%d %d %d\n", blank_count, tab_count, newline_count);
}

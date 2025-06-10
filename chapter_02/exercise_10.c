#include <stdio.h>
#include <stdlib.h>

int to_lower_char(int c);

int main(void) {
  int c;

  while ((c = getchar()) != EOF) {
    printf("%c\n", to_lower_char(c));
  }

  return EXIT_SUCCESS;
}

int to_lower_char(int c) { return c >= 'A' && c <= 'Z' ? (c + 'a' - 'A') : c; }

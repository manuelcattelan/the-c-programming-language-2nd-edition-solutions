#include <stdio.h>
#include <stdlib.h>

int lower(int c);

int main(void) {
  int c;
  while ((c = getchar()) != EOF) {
    printf("%c\n", lower(c));
  }
  return EXIT_SUCCESS;
}

int lower(int c) { return c >= 'A' && c <= 'Z' ? (c + 'a' - 'A') : c; }

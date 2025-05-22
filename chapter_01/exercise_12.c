#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int c;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n')
      putchar(c);
    else
      printf("\n");
  }
  return EXIT_SUCCESS;
}

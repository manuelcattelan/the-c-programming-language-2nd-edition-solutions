#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int c;
  /* There is no correct default value for the previous character read,
   * but EOF is a good representation of the fact that no valid character has
   * been read yet. */
  int c_prev = EOF;

  while ((c = getchar()) != EOF) {
    if (c != ' ' || (c == ' ' && c_prev != ' ')) {
      putchar(c);
    }
    c_prev = c;
  }

  return EXIT_SUCCESS;
}

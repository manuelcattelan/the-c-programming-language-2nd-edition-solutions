#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int c;
  /* NOTE: there is no correct default value for the last seen character, but
   * EOF is a good representation of the fact that no valid character has been
   * read yet, making it a great choice for our usecase. */
  int lc = EOF;
  while ((c = getchar()) != EOF) {
    if (c != ' ' || (c == ' ' && lc != ' '))
      putchar(c);
    lc = c;
  }
  return EXIT_SUCCESS;
}

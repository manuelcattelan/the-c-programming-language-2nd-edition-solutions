#include <stdio.h>
#include <stdlib.h>

#define TABSTOPS 8 /* number of columns that a tabstop character expands to */

int main(void) {
  int c;
  int cpos = 0; /* character position inside the current line */
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      int nb = TABSTOPS - (cpos % TABSTOPS);
      for (int i = 0; i < nb; ++i)
        putchar(' ');
      cpos += nb;
    } else {
      putchar(c);
      cpos = (c == '\n') ? 0 : cpos + 1;
    }
  }
  return EXIT_SUCCESS;
}

/* The number of tabstops is better suited to be a symbolic parameter as this
 * allows us to define it's value only once, improving our program's
 * mantainability and making it easier to customize it's value in the future if
 * necessary. */

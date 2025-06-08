#include <stdio.h>
#include <stdlib.h>

#define TABSTOPS 8 /* number of columns that a tabstop character expands to */

int main(void) {
  int c;
  int c_pos = 0; /* character position inside the current line */
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      int num_blanks = TABSTOPS - (c_pos % TABSTOPS);
      for (int i = 0; i < num_blanks; ++i, ++c_pos) {
        putchar(' ');
      }
    } else {
      putchar(c);
      c_pos = (c == '\n') ? 0 : c_pos + 1;
    }
  }
  return EXIT_SUCCESS;
}

/* The number of tabstops is better suited to be a symbolic parameter as this
 * allows us to define it's value only once, improving our program's
 * mantainability and making it easier to customize it's value in the future if
 * necessary by only needing to edit it in one place. */

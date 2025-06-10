#include <stdio.h>
#include <stdlib.h>

#define TABSTOPS 8 /* number of columns that a tabstop character expands to */

int main(void) {
  int c;
  int c_pos = 0; /* character position in the line being read */

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

/* The number of tabstops is better suited to be a symbolic parameter as it is
 * fixed for the entire program execution and the value is substituted at
 * compile time, meaning there is no runtime overhead when it is used. */

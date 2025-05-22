#include <stdio.h>
#include <stdlib.h>

#define TABSTOPS 8 /* number of columns that a tabstop character expands to */

int main(void) {
  int c;
  int cpos = 0; /* character position inside the current line */
  int nb = 0;   /* number of consecutive blanks */
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++cpos;
      ++nb;
      if ((cpos % TABSTOPS) == 0) {
        putchar('\t');
        nb = 0;
      }
    } else {
      if (nb > 0)
        for (int i = 0; i < nb; ++i)
          putchar(' ');
      nb = 0;
      putchar(c);
      cpos = (c == '\n') ? 0 : cpos + 1;
    }
  }
  return EXIT_SUCCESS;
}

/* When either a tab or a single blank would suffice to reach a tab stop a tab
 * should be given precedence, as the exercise specifically asks to replace all
 * possible strings of blanks by the minimum number of tabs and blanks to
 * achieve the same spacing. */

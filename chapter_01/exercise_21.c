#include <stdio.h>
#include <stdlib.h>

#define TABSTOPS 8 /* number of columns that a tabstop character expands to */

int main(void) {
  int c;
  /* This keeps track of the character position inside the current line, but it
   * does not necessarily reflect the number of characters that we've printed
   * in the output at a given moment. This is because we defer printing blank
   * characters only when we know we can't expand those to tab characters. */
  int c_pos = 0;
  int num_blanks = 0; /* number of consecutive blank characters */
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++c_pos;
      ++num_blanks;
      if ((c_pos % TABSTOPS) == 0) {
        putchar('\t');
        num_blanks = 0;
      }
    } else {
      /* If the number of consecutive encountered blanks here is non-zero, that
       * means we've found a number of them that wasn't enough to be converted
       * into a tab character. Since we do not immediately print out blank
       * characters, the following for-loop flushes all consumed blanks that
       * were encountered before the current non-blank character. */
      if (num_blanks > 0) {
        for (int i = 0; i < num_blanks; ++i) {
          putchar(' ');
        }
      }
      num_blanks = 0;
      if (c == '\t') {
        c_pos += TABSTOPS - (c_pos % TABSTOPS);
      } else {
        c_pos = (c == '\n') ? 0 : c_pos + 1;
      }
      putchar(c);
    }
  }
  return EXIT_SUCCESS;
}

/* When either a tab or a single blank would suffice to reach a tab stop a tab
 * should be given precedence, as the exercise specifically asks to replace all
 * possible strings of blanks by the minimum number of tabs and blanks to
 * achieve the same spacing. */

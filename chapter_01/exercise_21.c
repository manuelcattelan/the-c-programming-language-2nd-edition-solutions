#include <stdio.h>
#include <stdlib.h>

#define TABSTOPS 8 /* number of columns that a tabstop character expands to */

int main(void) {
  int c;
  int c_pos = 0;      /* character position in the line being read */
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
      /* If the number of consecutive blanks here is non-zero, it means they
       * weren't enough to be converted into a tab character. Since we do not
       * immediately print out blank characters, the following for-loop flushes
       * all pending blanks. */
      for (; num_blanks > 0; --num_blanks) {
        putchar(' ');
      }
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
 * achieve the same spacing. Furthermore, a tab character is more
 * space-efficient than a space when it represents multiple columns. */

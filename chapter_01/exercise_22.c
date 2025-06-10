#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 80 /* threshold after which an input line gets folded */
#define TABSTOPS 8 /* number of blanks that a tabstop character expands to */

int main(void) {
  int c;
  int c_pos = 0;      /* character position inside the current OUTPUT line */
  int num_blanks = 0; /* number of consecutive blank characters */

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++num_blanks;
    } else if (c == '\t') {
      /* If we encounter a tab character we expand it by making it appear like
       * we had consumed the number of blanks necessary to reach the next tab
       * stop. The calculation takes into consideration the fact that when we
       * consume a blank we do not increase c_pos but only num_blanks. */
      num_blanks += TABSTOPS - ((c_pos + num_blanks) % TABSTOPS);
    } else if (c == '\n') {
      c_pos = num_blanks = 0;
    } else {
      /* If we encounter any other character, we flush all previously consumed
       * blanks (and tabs converted to blanks) because it means that those
       * blanks were not trailing characters, and we don't want to remove them
       * from the folded line. */
      for (; num_blanks > 0; --num_blanks) {
        if (c_pos == MAX_LINE_LEN - 1) {
          putchar('\n');
          c_pos = 0;
        }
        putchar(' ');
        ++c_pos;
      }
      /* Fold lines longer than the threshold, preserving a space for the
       * newline character by breaking one character before the actual limit. */
      if (c_pos == MAX_LINE_LEN - 1) {
        putchar('\n');
        c_pos = 0;
      }
      putchar(c);
      ++c_pos;
    }
  }

  return EXIT_SUCCESS;
}

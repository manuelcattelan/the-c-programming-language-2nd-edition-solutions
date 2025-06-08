#include <stdio.h>
#include <stdlib.h>

/* Maximum number of characters to be considered for each line that we read from
 * input before it gets folded. */
#define MAX_LINE_LEN 10
#define TABSTOPS 8 /* number of blanks that a tabstop character expands to */

int main(void) {
  int c;
  int c_pos = 0;      /* character position inside the current OUTPUT line */
  int num_blanks = 0; /* number of consecutive blank characters */
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++num_blanks;
    }
    /* If we encounter a tab character we expand it by making it appear like we
     * had consumed the number of blanks necessary to reach the next tab stop.
     * The calculation takes into consideration the fact that when we consume
     * a blank we do not increase c_pos but only num_blanks. */
    else if (c == '\t') {
      num_blanks += TABSTOPS - ((c_pos + num_blanks) % TABSTOPS);
    }
    /* If we encounter a newline character we simply reset counters for any
     * pending blank character, since we actually want to remove trailing
     * blanks. */
    else if (c == '\n') {
      c_pos = num_blanks = 0;
    } else {
      /* If we encounter any other character, we flush all previously consumed
       * blanks (and tabs converted to blanks) because it means that those
       * blanks were not trailing characters, and we don't want to remove them
       * from the folded line. */
      if (num_blanks > 0) {
        for (; num_blanks > 0; --num_blanks) {
          if (c_pos == MAX_LINE_LEN - 1) {
            putchar('\n');
            c_pos = 0;
          }
          putchar(' ');
          ++c_pos;
        }
      }
      /* This simple logic is the one responsible for actually folding lines
       * longer than the maximum allowed. Notice that we also preserve a space
       * for the newline character by breaking one character before the actual
       * limit. */
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

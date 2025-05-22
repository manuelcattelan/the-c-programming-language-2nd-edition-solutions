#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 80 /* maximum length of a line before it gets folded */
#define TABSTOPS 8 /* number of blanks that a tabstop character expands to */

int main(void) {
  int c;
  int cpos = 0; /* character position inside the current line */
  int nb = 0;   /* number of consecutive blanks */
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++cpos;
      ++nb;
    } else if (c == '\n') {
      putchar(c);
      cpos = nb = 0;
    } else if (c == '\t') {
      /* Expand tab into the correct number of blank characters by incrementing
       * the blanks count that will be flushed at the next non-blank character,
       * if it exists. */
      int nbt = TABSTOPS - (cpos % TABSTOPS);
      for (int i = 0; i < nbt; ++i) {
        ++cpos;
        ++nb;
      }
    } else {
      /* When we reach a non-blank character that is none of the above, flush
       * any previously met blank characters that fit into the current line. */
      while (nb > 0 && cpos - nb < MAXLINE) {
        putchar(' ');
        --nb;
      }
      /* It may be the case that after flushing the blank characters above, we
       * will still need to go to a new line because there are even more
       * characters to handle: we fold the current line for this reason. */
      if (cpos >= MAXLINE) {
        putchar('\n');
        cpos = nb;
      }
      /* The following flushes all consecutive blank characters before the
       * current non-blank one. Of course we still need to handle line folding,
       * so we only print MAXLINE blank characters in each line at most. */
      while (nb > 0) {
        int nbmax = nb < MAXLINE ? nb : MAXLINE;
        for (int i = 0; i < nbmax; ++i, --nb)
          putchar(' ');
        if (nbmax == MAXLINE) {
          putchar('\n');
          cpos = nb;
        }
      }
      /* If, after flushing all blank characters, we exactly reached the "end"
       * of the current line (meaning there is no more space for the new
       * character in the current line), we fold the current line before
       * outputting the new character. */
      if (cpos >= MAXLINE) {
        putchar('\n');
        cpos = 0;
      }
      putchar(c);
      ++cpos;
    }
  }
  return EXIT_SUCCESS;
}

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  OUTSIDE, /* status that represents being outside a word */
  INSIDE   /* status that represents being inside a word */
} WordStatus;

int main(void) {
  int c;
  WordStatus w_status = OUTSIDE;

  while ((c = getchar()) != EOF) {
    /* The definition of word for this program is any sequence of characters
     * that does not contain a white-space character (not to be confused with
     * the blank character). */
    if (isspace(c)) {
      if (w_status == INSIDE) {
        putchar('\n');
        w_status = OUTSIDE;
      }
    } else {
      putchar(c);
      if (w_status == OUTSIDE) {
        w_status = INSIDE;
      }
    }
  }
  /* It may be the case that input does not end with a white-space character and
   * the following handle just that, printing a newline character after we've
   * finished reading from input if we were still inside a word.*/
  if (w_status == INSIDE) {
    putchar('\n');
  }

  return EXIT_SUCCESS;
}

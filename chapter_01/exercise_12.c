#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  OUTSIDE, /* status that represents being outside a word while reading input */
  INSIDE   /* status that represents being inside a word while reading input */
} WordStatus;

int main(void) {
  int c;
  WordStatus w_status = OUTSIDE;
  while ((c = getchar()) != EOF) {
    if (!isspace(c)) {
      putchar(c);
      w_status = INSIDE;
    } else if (w_status == INSIDE) {
      putchar('\n');
      w_status = OUTSIDE;
    }
  }
  /* This handles the case where the input ends with a non-space character like
   * which would be otherwise caught by the if-statement at line 13 so that we
   * print a trailing newline after the last word in the input. */
  if (w_status == INSIDE) {
    putchar('\n');
  }
  return EXIT_SUCCESS;
}

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum number of characters to be considered for each word that we read from
 * input, which also represents the number of word lengths that will be printed
 * inside the histogram. */
#define MAX_WORD_LEN 10

typedef enum {
  OUTSIDE, /* status that represents being outside a word while reading input */
  INSIDE   /* status that represents being inside a word while reading input */
} WordStatus;

int main(void) {
  int c;
  int w_len = 0;                 /* length of the current word */
  int w_len_count[MAX_WORD_LEN]; /* count of each considered word length */
  WordStatus w_status = OUTSIDE;
  for (int i = 0; i < MAX_WORD_LEN; ++i) {
    w_len_count[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (isspace(c)) {
      w_status = OUTSIDE;
      if (w_len > 0 && w_len <= MAX_WORD_LEN) {
        ++w_len_count[w_len - 1];
      }
      w_len = 0;
    } else {
      if (w_status == OUTSIDE) {
        w_status = INSIDE;
      }
      ++w_len;
    }
  }
  /* It may happen that an input does not end with a space and the following
   * handles just that: by checking if we've read some word length we can
   * understand whether the while-loop exited without following the isspace(c)
   * branch and while inside a word. We take that last word into consideration
   * with the following if-statement. */
  if (w_len > 0 && w_len <= MAX_WORD_LEN)
    ++w_len_count[w_len - 1];
  for (int i = 0; i < MAX_WORD_LEN; ++i) {
    printf("\n%2d: ", i + 1);
    for (int j = 0; j < w_len_count[i]; ++j)
      printf("█");
    printf("\n");
  }
  return EXIT_SUCCESS;
}

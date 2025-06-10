#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* Words longer than this threshold will simply be ignored and their presence
 * will make no difference in the output histogram. */
#define MAX_WORD_LEN 10

typedef enum {
  OUTSIDE, /* status that represents being outside a word */
  INSIDE   /* status that represents being inside a word */
} WordStatus;

int main(void) {
  int c;
  int w_len = 0; /* length of the current word being read */
  /* Each array index represents a specific word length and the value of the
   * array at a specific index is the number of words that have been read with
   * length equal to index + 1. */
  int w_len_count[MAX_WORD_LEN] = {0};
  WordStatus w_status = OUTSIDE;

  while ((c = getchar()) != EOF) {
    /* The definition of word for this program is any sequence of characters
     * that does not contain a white-space character (not to be confused with
     * the blank character). */
    if (isspace(c)) {
      if (w_len > 0 && w_len <= MAX_WORD_LEN) {
        ++w_len_count[w_len - 1];
      }
      w_len = 0;
      if (w_status == INSIDE) {
        w_status = OUTSIDE;
      }
    } else {
      ++w_len;
      if (w_status == OUTSIDE) {
        w_status = INSIDE;
      }
    }
  }
  /* It may be the case that input does not end with a white-space character and
   * the following handle just that, also taking into consideration the very
   * last word from input. */
  if (w_len > 0 && w_len <= MAX_WORD_LEN) {
    ++w_len_count[w_len - 1];
  }

  for (int i = 0; i < MAX_WORD_LEN; ++i) {
    printf("%2d: ", i + 1);
    for (int j = 0; j < w_len_count[i]; ++j) {
      printf("█");
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}

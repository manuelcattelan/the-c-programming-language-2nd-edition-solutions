#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  OUTSIDE, /* status that represents being outside a word */
  INSIDE   /* status that represents being inside a word */
} WordStatus;

int main(void) {
  int c;
  int num_lines = 0;      /* number of occurrencies of newline characters */
  int num_words = 0;      /* number of words */
  int num_characters = 0; /* number of characters */
  WordStatus w_status = OUTSIDE;

  while ((c = getchar()) != EOF) {
    ++num_characters;
    if (c == '\n') {
      ++num_lines;
    }
    /* The definition of word for this program is any sequence of characters
     * that does not contain a white-space character (not to be confused with
     * the blank character). */
    if (isspace(c)) {
      if (w_status == INSIDE) {
        w_status = OUTSIDE;
      }
    } else {
      if (w_status == OUTSIDE) {
        ++num_words;
        w_status = INSIDE;
      }
    }
  }

  printf("Number of lines: %d\n", num_lines);
  printf("Number of words: %d\n", num_words);
  printf("Number of characters: %d\n", num_characters);

  return EXIT_SUCCESS;
}

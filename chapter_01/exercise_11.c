#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  OUTSIDE, /* status that represents being outside a word while reading input */
  INSIDE   /* status that represents being inside a word while reading input */
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
    if (isspace(c)) {
      w_status = OUTSIDE;
    } else if (w_status == OUTSIDE) {
      w_status = INSIDE;
      ++num_words;
    }
  }
  printf("Number of lines: %d\n", num_lines);
  printf("Number of words: %d\n", num_words);
  printf("Number of characters: %d\n", num_characters);
  return EXIT_SUCCESS;
}

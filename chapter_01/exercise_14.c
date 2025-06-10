#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* Number of unique characters for which we count occurrencies (in this
 * case lowercase alphabetic characters a-z). This is very important because,
 * based on this implication, we're can safely convert array indices to their
 * character representation and viceversa. */
#define UNIQUE_CHARS_COUNT 26

int main(void) {
  int c;
  /* Each array index represents a specific character when the value of 'a' gets
   * added to it and the value of the array at a specific index is the number of
   * occurrencies that have been read of that specific character. */
  int c_count[UNIQUE_CHARS_COUNT] = {0};

  while ((c = getchar()) != EOF) {
    if (islower(c)) {
      ++c_count[c - 'a'];
    }
  }

  for (int i = 0; i < UNIQUE_CHARS_COUNT; ++i) {
    printf("\n%c: ", i + 'a');
    for (int j = 0; j < c_count[i]; ++j) {
      printf("█");
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}

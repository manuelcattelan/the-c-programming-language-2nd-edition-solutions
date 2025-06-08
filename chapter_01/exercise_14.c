#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* Number of unique characters for which we count occurrencies (in this case
 * being lower case alphabetical characters) which also represents the number of
 * character occurrencies that will be printed inside the histogram. */
#define MAX_CHAR 26

int main(void) {
  int c;
  int c_count[MAX_CHAR]; /* count of each considered character */
  for (int i = 0; i < MAX_CHAR; ++i) {
    c_count[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (islower(c)) {
      ++c_count[c - 'a'];
    }
  }
  for (int i = 0; i < MAX_CHAR; ++i) {
    printf("\n%c: ", i + 'a');
    for (int j = 0; j < c_count[i]; ++j) {
      printf("█");
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}

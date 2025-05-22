#include <stdio.h>
#include <stdlib.h>

#define NUMCHAR 26 /* only consider lower case alphabetical characters */

int main(void) {
  int c;
  int co[NUMCHAR]; /* count of occurrencies for each considered character */
  for (int i = 0; i < NUMCHAR; ++i)
    co[i] = 0;
  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z')
      ++co[c - 'a'];
  }
  for (int i = 0; i < NUMCHAR; ++i) {
    printf("\n%c: ", i + 'a');
    for (int j = 0; j < co[i]; ++i)
      printf("█");
    if (i != NUMCHAR - 1)
      printf("\n |");
  }
  return EXIT_SUCCESS;
}

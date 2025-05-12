#include <stdio.h>

/* See `https://en.wikipedia.org/wiki/Escape_sequences_in_C` for a full list of
 * escape sequences, including non-standard ones. */
int main() {
  printf("\a");
  printf("\b");
  printf("\f");
  printf("\n");
  printf("\r");
  printf("\t");
  printf("\v");
  printf("\\");
  printf("\'");
  printf("\"");
  printf("\?");
  printf("\11");
  printf("\x11");
  printf("\u00C0");
  printf("\U0000FFFF");
}

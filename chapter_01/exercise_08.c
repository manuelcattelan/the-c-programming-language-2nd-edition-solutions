#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int c;
  int num_blanks = 0;   /* number of occurrencies of blank characters */
  int num_tabs = 0;     /* number of occurrencies of tab characters */
  int num_newlines = 0; /* number of occurrencies of newline characters */

  while ((c = getchar()) != EOF) {
    switch (c) {
      case ' ':
        ++num_blanks;
        break;
      case '\t':
        ++num_tabs;
        break;
      case '\n':
        ++num_newlines;
        break;
      default:
        break;
    }
  }

  printf("Number of blank characters: %d\n", num_blanks);
  printf("Number of tab characters: %d\n", num_tabs);
  printf("Number of newline characters: %d\n", num_newlines);

  return EXIT_SUCCESS;
}

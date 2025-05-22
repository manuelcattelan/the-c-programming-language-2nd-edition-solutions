#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int c;
  int nb = 0; /* number of blanks */
  int nt = 0; /* number of tabs */
  int nl = 0; /* number of newlines */
  while ((c = getchar()) != EOF) {
    switch (c) {
      case ' ':
        ++nb;
        break;
      case '\t':
        ++nt;
        break;
      case '\n':
        ++nl;
        break;
      default:
        break;
    }
  }
  printf("%d %d %d\n", nb, nt, nl);
  return EXIT_SUCCESS;
}

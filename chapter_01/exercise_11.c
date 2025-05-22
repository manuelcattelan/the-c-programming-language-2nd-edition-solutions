#include <stdio.h>
#include <stdlib.h>

enum boolean {
  OUT, /* state that represents being inside a word */
  IN   /* state that represents being outside a word */
};

int main(void) {
  int c;
  int nl = 0;       /* number of newlines */
  int nw = 0;       /* number of words */
  int nc = 0;       /* number of characters */
  int status = OUT; /* tracks if we're currently inside a word or not */
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\t' || c == '\n')
      status = OUT;
    else if (status == OUT) {
      status = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
  return EXIT_SUCCESS;
}

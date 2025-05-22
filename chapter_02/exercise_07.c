#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);

int main(void) {
  printf("%u\n", invert(255, 4, 3));
  return EXIT_SUCCESS;
}

unsigned invert(unsigned x, int p, int n) {
  /* The following steps are divided as follows:
   *   1. We create a mask of n 1-bits at position p;
   *   2. We OR (exclusive) the mask we just created with x, resulting in n
   *      bytes from position p in x to be inverted.
   * This works becouse an exclusive OR with 1s inverts bits, while an exclusive
   * OR with 0s leaves them unchanged. */
  unsigned xm = (~(~0 << n)) << (p + 1 - n);
  return x ^ xm;
}

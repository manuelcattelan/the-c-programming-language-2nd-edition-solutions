#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void) {
  printf("%u\n", setbits(255, 4, 3, 16));
  return EXIT_SUCCESS;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  /* The following steps are divided as follows:
   *   1. We create a mask of n 1-bits at the rightmost position and AND it with
   *      y, resulting in a byte with all 0s except for the rightmost bits,
   *      which will be equal to those in y for the same positions;
   *   2. We shift the byte we just created to have the leftmost bit at position
   *      p;
   *   3. We clear (set to 0) n bits starting from position p in x;
   *   4. We OR both bytes together, resulting in n bytes from position p in x
   *      to be equal to n bytes from position p in y. */
  unsigned ym = y & ~(~0 << n);
  unsigned yms = ym << (p + 1 - n);
  unsigned xm = x & ~(~(~0 << n) << (p + 1 - n));
  return xm | yms;
}

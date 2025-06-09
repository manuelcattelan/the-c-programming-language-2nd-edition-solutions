#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void) {
  unsigned x = 255;
  unsigned y = 16;
  int from = 4;
  int num_bits = 3;
  printf("%u\n", setbits(x, from, num_bits, y));
  return EXIT_SUCCESS;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  /* We create a mask of n 1-bits at the rightmost position and AND it with y,
   * resulting in a byte with all 0s except for the rightmost bits, which will
   * be equal to those in y for the same positions. */
  unsigned y_mask = y & ~(~0 << n);
  /* We shift the byte we just created to have the leftmost bit of the range
   * we're considering at position p. */
  unsigned y_mask_shifted = y_mask << (p + 1 - n);
  /* We clear (set to 0) n bits starting from position p in x. */
  unsigned x_mask_shifted = x & ~(~(~0 << n) << (p + 1 - n));
  /* We OR both bytes together, resulting in n bytes from position p in x to be
   * equal to n bytes from position p in y. */
  return x_mask_shifted | y_mask_shifted;
}

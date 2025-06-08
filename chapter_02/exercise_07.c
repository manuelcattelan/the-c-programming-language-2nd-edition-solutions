#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);

int main(void) {
  unsigned x = 255;
  int from = 4;
  int num_bits = 3;
  printf("%u\n", invert(x, from, num_bits));
  return EXIT_SUCCESS;
}

unsigned invert(unsigned x, int p, int n) {
  /* We create a mask of n 1-bits at position p. */
  unsigned x_mask = (~(~0 << n)) << (p + 1 - n);
  /* We OR (exclusive) the mask we just created with x, resulting in n bytes
   * from position p in x to be inverted. This is the simplest way to do such
   * operation because an exclusive OR with 1s inverts bits, while an exclusive
   * OR with 0s leaves them unchanged. */
  return x ^ x_mask;
}

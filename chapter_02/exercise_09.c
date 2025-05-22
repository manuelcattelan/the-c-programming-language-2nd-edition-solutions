#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x);

int main(void) {
  printf("%u\n", bitcount(255));
  return EXIT_SUCCESS;
}

int bitcount(unsigned x) {
  int b;
  /* This works because in a two's complement number system, x &= (x - 1)
   * deletes the rightmost 1-bit in x. This comes from the fact that by
   * subtracting 1 to x, we're always turning the rightmost 1-bit of x to 0,
   * while all 0s to the right of that 1-bit become 1 and all bits to the left
   * of that 1-bit remain unchanged. The result is that using the AND operator
   * with the initial x and (x - 1), any bit from the position of the leftmost
   * (included) will become 0. */
  for (b = 0; x != 0; x &= (x - 1))
    b++;
  return b;
}

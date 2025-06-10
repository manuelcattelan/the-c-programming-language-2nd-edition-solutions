#include <stdio.h>
#include <stdlib.h>

int count_bits(unsigned x);

int main(void) {
  unsigned x = 255;

  printf("%d\n", count_bits(x));

  return EXIT_SUCCESS;
}

int count_bits(unsigned x) {
  int num_bits = 0;
  /* This works because in a two's complement number system, x &= (x - 1)
   * deletes the rightmost 1-bit in x, which is the result of the fact that by
   * subtracting 1 to x, we're always turning the rightmost 1-bit of x to 0,
   * while all 0s to the right of that 1-bit become 1 and all bits to the left
   * of that 1-bit remain unchanged. The result is that using the AND operator
   * with the initial x and (x - 1), any bit from the position of the leftmost
   * (included) will become 0. */
  for (; x != 0; x &= (x - 1)) {
    num_bits++;
  }

  return num_bits;
}

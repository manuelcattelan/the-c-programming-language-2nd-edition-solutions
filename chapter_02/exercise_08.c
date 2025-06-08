#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, int n);

int main(void) {
  unsigned x = 255;
  int num_bits = 3;
  printf("%u\n", rightrot(x, num_bits));
  return EXIT_SUCCESS;
}

unsigned rightrot(unsigned x, int n) {
  /* We compute the bitsize of unsigned variables in the current machine. */
  int x_size = sizeof(unsigned) * 8;
  /* We shift x by n positions to the right, resulting in the rightmost n bits
   * to be lost and the leftmost n positions to be filled with 0s. */
  unsigned x_shifted_right = x >> n;
  /* We shift x to the left by the amount of positions that make the rightmost n
   * bits that we had lost in the previous step move to the leftmost positions,
   * by making use of the size of x. */
  unsigned x_shifted_left = x << (x_size - n);
  /* We OR the results from the previous steps together since the first one had
   * 0s on the left and the second one had 0s on the right, resulting in the
   * correct combination of both. */
  return x_shifted_right | x_shifted_left;
}

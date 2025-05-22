#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, int n);

int main(void) {
  printf("%u\n", rightrot(255, 4));
  return EXIT_SUCCESS;
}

unsigned rightrot(unsigned x, int n) {
  /* The following steps are divided as follows:
   *   1. We compute the bitsize of unsigned variables in the current machine;
   *   2. We shift x by n positions to the right, resulting in the rightmost n
   *      bits to be lost and the leftmost n positions to be filled with 0s;
   *   3. We shift x to the left by the amount of positions that make the
   *      rightmost n bits that we had lost in the previous step move to the
   *      leftmost positions;
   *   4. We OR the results from the previous steps together since the first one
   *      had 0s on the left and the second one had 0s on the right, resulting
   *      in the correct combination of both. */
  int xs = sizeof(unsigned) * 8;
  return (x >> n) | (x << (xs - n));
}

#include <stdio.h>
#include <stdlib.h>

#define MIN_FAHR 0        /* minimum value for fahr variable */
#define MAX_FAHR 300      /* maximum value for fahr variable */
#define FAHR_DECREMENT 20 /* decrement between fahr variable values */

int main(void) {
  for (int fahr = MAX_FAHR; fahr >= MIN_FAHR; fahr -= FAHR_DECREMENT) {
    printf("%3d %5.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
  return EXIT_SUCCESS;
}

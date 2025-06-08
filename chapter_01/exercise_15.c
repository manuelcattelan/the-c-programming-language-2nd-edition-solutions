#include <stdio.h>
#include <stdlib.h>

#define MIN_FAHR 0        /* minimum value for fahr variable */
#define MAX_FAHR 300      /* maximum value for fahr variable */
#define FAHR_INCREMENT 20 /* increment between fahr variable values */

float fahr_to_celsius(int fahr);

int main(void) {
  for (int fahr = MIN_FAHR; fahr <= MAX_FAHR; fahr += FAHR_INCREMENT) {
    printf("%3d %5.1f\n", fahr, fahr_to_celsius(fahr));
  }
  return EXIT_SUCCESS;
}

float fahr_to_celsius(int fahr) { return (5.0 / 9.0) * (fahr - 32.0); }

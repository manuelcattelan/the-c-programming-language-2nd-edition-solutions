#include <stdio.h>
#include <stdlib.h>

#define LOWER 0   /* minimum value for fahrenheits variable */
#define UPPER 300 /* maximum value for fahrenheits variable */
#define STEP 20   /* increment between fahrenheits variable values */

float fahr_to_celsius(int fahr);

int main(void) {
  for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
    printf("%3d %5.1f\n", fahr, fahr_to_celsius(fahr));
  return EXIT_SUCCESS;
}

float fahr_to_celsius(int fahr) { return (5.0 / 9.0) * (fahr - 32.0); }

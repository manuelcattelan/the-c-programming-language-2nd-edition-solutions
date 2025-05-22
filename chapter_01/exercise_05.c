#include <stdio.h>
#include <stdlib.h>

#define LOWER 0   /* minimum value for fahrenheits variable */
#define UPPER 300 /* maximum value for fahrenheits variable */
#define STEP 20   /* increment between fahrenheits variable values */

int main(void) {
  for (int fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    printf("%3d %5.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

#define LOWER 0   /* minimum value for celsius variable */
#define UPPER 100 /* maximum value for celsius variable */
#define STEP 10   /* increment between celsius variable values */

int main(void) {
  for (int celsius = LOWER; celsius <= UPPER; celsius += STEP)
    printf("%3d %3.0f\n", celsius, celsius * (9.0 / 5.0) + 32.0);
  return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

#define MIN_CELSIUS 0        /* minimum value for celsius variable */
#define MAX_CELSIUS 300      /* maximum value for celsius variable */
#define CELSIUS_INCREMENT 20 /* increment between celsius variable values */

int main(void) {
  for (int celsius = MIN_CELSIUS; celsius <= MAX_CELSIUS;
       celsius += CELSIUS_INCREMENT) {
    printf("%3d %3.0f\n", celsius, celsius * (9.0 / 5.0) + 32.0);
  }
  return EXIT_SUCCESS;
}

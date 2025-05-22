#include <stdio.h>
#include <stdlib.h>

#define LOWER 0   /* minimum value for fahrenheits variable */
#define UPPER 300 /* maximum value for fahrenheits variable */
#define STEP 20   /* increment between fahrenheits variable values */

int main(void) {
  printf("┌───────────────────────┐\n");
  printf("│ Fahrenheit to Celsius │\n");
  printf("└───────────────────────┘\n");
  for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
    printf("%12d %10.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  return EXIT_SUCCESS;
}

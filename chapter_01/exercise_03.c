#include <stdio.h>
#include <stdlib.h>

#define MIN_FAHR 0
#define MAX_FAHR 300
#define FAHR_INCREMENT 20

int main(void) {
  printf("┌───────────────────────┐\n");
  printf("│ Fahrenheit to Celsius │\n");
  printf("└───────────────────────┘\n");

  for (int fahr = MIN_FAHR; fahr <= MAX_FAHR; fahr += FAHR_INCREMENT) {
    printf("%12d %10.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }

  return EXIT_SUCCESS;
}

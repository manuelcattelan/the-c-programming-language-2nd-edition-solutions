#include <stdio.h>
#include <stdlib.h>

#define MIN_FAHR 0
#define MAX_FAHR 300
#define FAHR_INCREMENT 20

float fahr_to_celsius(int fahr);

int main(void) {
  for (int fahr = MIN_FAHR; fahr <= MAX_FAHR; fahr += FAHR_INCREMENT) {
    printf("%3d %5.1f\n", fahr, fahr_to_celsius(fahr));
  }

  return EXIT_SUCCESS;
}

float fahr_to_celsius(int fahr) { return (5.0 / 9.0) * (fahr - 32.0); }

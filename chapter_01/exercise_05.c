#include <stdio.h>
#include <stdlib.h>

#define MIN_FAHR 0
#define MAX_FAHR 300
#define FAHR_DECREMENT 20

int main(void) {
  for (int fahr = MAX_FAHR; fahr >= MIN_FAHR; fahr -= FAHR_DECREMENT) {
    printf("%3d %5.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }

  return EXIT_SUCCESS;
}

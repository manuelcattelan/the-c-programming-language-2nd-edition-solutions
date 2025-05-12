#include <stdio.h>
#include <stdlib.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahrenheit_to_celsius(int fahrenheit);

int main() {
  for (int fahrenheit = LOWER; fahrenheit <= UPPER;
       fahrenheit = fahrenheit + STEP)
    printf("%3d %6.1f\n", fahrenheit, fahrenheit_to_celsius(fahrenheit));
  return EXIT_SUCCESS;
}

float fahrenheit_to_celsius(int fahrenheit) {
  return (5.0 / 9.0) * (fahrenheit - 32.0);
}

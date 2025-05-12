#include <stdio.h>

int main() {
  float fahrenheit, celsius;
  int lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20;
  printf("-------------------------\n");
  printf("| Fahrenheit to Celsius |\n");
  printf("-------------------------\n");
  printf("\n");
  fahrenheit = lower;
  while (fahrenheit <= upper) {
    celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
    printf("%12.0f %12.1f\n", fahrenheit, celsius);
    fahrenheit = fahrenheit + step;
  }
}

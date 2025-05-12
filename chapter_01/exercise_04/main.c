#include <stdio.h>

int main() {
  float fahrenheit, celsius;
  int lower, upper, step;
  lower = 0;
  upper = 100;
  step = 10;
  celsius = lower;
  while (celsius <= upper) {
    fahrenheit = celsius * (9.0 / 5.0) + 32.0;
    printf("%9.0f %13.0f\n", celsius, fahrenheit);
    celsius = celsius + step;
  }
}

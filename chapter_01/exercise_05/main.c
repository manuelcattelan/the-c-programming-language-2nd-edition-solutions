#include <stdio.h>

int main() {
  for (int fahrenheit = 300; fahrenheit >= 0; fahrenheit = fahrenheit - 20)
    printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32.0));
}

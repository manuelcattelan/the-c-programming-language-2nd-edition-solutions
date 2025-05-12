#include <stdio.h>

int main() {
  int character;
  while ((character = getchar()) != EOF) {
    if (character == '\t') {
      putchar('\\');
      putchar('t');
    }
    if (character == '\b') {
      putchar('\\');
      putchar('b');
    }
    if (character == '\\') {
      putchar('\\');
      putchar('\\');
    }
    if (character != '\t') {
      if (character != '\b') {
        if (character != '\\') {
          putchar(character);
        }
      }
    }
  }
  printf("\n");
}

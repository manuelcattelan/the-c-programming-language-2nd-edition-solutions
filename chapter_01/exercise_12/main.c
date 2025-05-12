#include <stdio.h>

int main() {
  int character;
  while ((character = getchar()) != EOF) {
    if (character != ' ' && character != '\t' && character != '\n')
      putchar(character);
    else
      printf("\n");
  }
  printf("\n");
}

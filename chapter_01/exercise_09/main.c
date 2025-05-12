#include <stdio.h>

int main() {
  int character, last_seen_character;
  // NOTE: there is no correct default value for the last seen character, but
  // EOF is a good representation of the fact that no valid character has been
  // read yet, making it a good choice for our usecase.
  last_seen_character = EOF;
  while ((character = getchar()) != EOF) {
    if (character != ' ')
      putchar(character);
    if (character == ' ') {
      if (last_seen_character != ' ')
        putchar(character);
    }
    last_seen_character = character;
  }
  printf("\n");
}

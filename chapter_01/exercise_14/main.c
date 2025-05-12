#include <stdio.h>

#define CONSIDERED_CHARACTERS_COUNT 26

int main() {
  int character;
  int characters_count[CONSIDERED_CHARACTERS_COUNT];
  for (int i = 0; i < CONSIDERED_CHARACTERS_COUNT - 1; i++)
    characters_count[i] = 0;
  while ((character = getchar()) != EOF) {
    if (character >= 'a' && character <= 'z')
      ++characters_count[character - 'a'];
  }
  for (int i = 0; i < CONSIDERED_CHARACTERS_COUNT; i++) {
    printf("\n%c: ", i + 'a');
    for (int j = 0; j < characters_count[i]; j++)
      printf("#");
  }
  printf("\n");
}

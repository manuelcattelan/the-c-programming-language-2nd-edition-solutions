#include <stdio.h>

#define INSIDE_WORD 1
#define OUTSIDE_WORD 0
#define MAX_WORD_LENGTH 10

int main() {
  int character, current_word_lenght, word_status;
  int word_lengths_count[MAX_WORD_LENGTH];
  current_word_lenght = 0;
  word_status = OUTSIDE_WORD;
  for (int i = 0; i < MAX_WORD_LENGTH; i++)
    word_lengths_count[i] = 0;
  while ((character = getchar()) != EOF) {
    if (character == ' ' || character == '\t' || character == '\n') {
      word_status = OUTSIDE_WORD;
      if (current_word_lenght > 0 && current_word_lenght <= MAX_WORD_LENGTH)
        ++word_lengths_count[current_word_lenght - 1];
      current_word_lenght = 0;
    } else {
      if (word_status == OUTSIDE_WORD)
        word_status = INSIDE_WORD;
      ++current_word_lenght;
    }
  }
  // Process the last word from input: this helps handle the case where input
  // comes from a terminal emulator and the EOF signal (CTRL+D or CTRL+Z) has
  // to be sent twice in order to actually be interpreted as such. In that case,
  // since there is no blank space, tab or newline after the word, it wouldn't
  // be considered in the code above.
  if (current_word_lenght > 0 && current_word_lenght <= MAX_WORD_LENGTH)
    ++word_lengths_count[current_word_lenght - 1];
  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("\n%2d: ", i + 1);
    for (int j = 0; j < word_lengths_count[i]; j++)
      printf("#");
  }
  printf("\n");
}

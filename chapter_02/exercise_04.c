#include <stdio.h>
#include <stdlib.h>

typedef enum {
  NOT_FOUND, /* current character is not one to delete */
  FOUND      /* current character is one to delete */
} CharacterStatus;

void squeeze(char s1[], const char s2[]);

int main(void) {
  char s1[] = "hello, world!z";
  char s2[] = "z";
  squeeze(s1, s2);
  printf("%s\n", s1);
  return EXIT_SUCCESS;
}

void squeeze(char s1[], const char s2[]) {
  int s1_idx, s2_idx, s1_pos;
  for (s1_idx = s1_pos = 0; s1[s1_idx] != '\0'; s1_idx++) {
    /* This variable tracks whether the current character of the given string
     * exists in the string of characters that should be removed from it. */
    CharacterStatus c_status = NOT_FOUND;
    for (s2_idx = 0; s2[s2_idx] != '\0'; s2_idx++) {
      if (s2[s2_idx] == s1[s1_idx]) {
        c_status = FOUND;
        break;
      }
    }
    if (c_status == NOT_FOUND) {
      s1[s1_pos++] = s1[s1_idx];
    }
  }
  s1[s1_pos] = '\0';
}

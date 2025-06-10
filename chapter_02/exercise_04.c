#include <stdio.h>
#include <stdlib.h>

typedef enum {
  NOT_FOUND, /* current character is not one to delete */
  FOUND      /* current character is one to delete */
} CharacterStatus;

void delete_chars(char from[], const char chars[]);

int main(void) {
  char from[] = "hello, world!z";
  char chars[] = "z";

  delete_chars(from, chars);
  printf("%s\n", from);

  return EXIT_SUCCESS;
}

void delete_chars(char from[], const char chars[]) {
  int c_pos = 0;

  for (int i = 0; from[i] != '\0'; i++) {
    CharacterStatus c_status = NOT_FOUND;
    for (int j = 0; chars[j] != '\0'; j++) {
      if (chars[j] == from[i]) {
        c_status = FOUND;
        break;
      }
    }
    if (c_status == NOT_FOUND) {
      from[c_pos++] = from[i];
    }
  }
  from[c_pos] = '\0';
}

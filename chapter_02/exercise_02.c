#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 1000

int main(void) {
  int c;
  int c_pos = 0; /* character position inside the current line */
  char s[MAX_STRING_LEN];
  while (c_pos < MAX_STRING_LEN - 1) {
    if ((c = getchar()) != '\n') {
      if (c != EOF) {
        s[c_pos++] = c;
      }
    }
  }
  return EXIT_SUCCESS;
}

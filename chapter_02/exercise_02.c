#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000 /* maximum length for string */

int main(void) {
  int c;
  int cc = 0;
  int s[MAXLEN];
  while (cc < MAXLEN - 1) {
    if ((c = getchar()) != '\n')
      if (c != EOF)
        s[cc++] = c;
  }
  return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

#define MAXWORD 10 /* maximum length for a word to be considered */
enum boolean {
  OUT, /* state that represents being inside a word */
  IN   /* state that represents being outside a word */
};

int main(void) {
  int c;
  int wlen = 0;       /* length of the current word */
  int wlenc[MAXWORD]; /* count of words for each considered word length */
  int status = OUT;   /* tracks if we're currently inside a word or not */
  for (int i = 0; i < MAXWORD; ++i)
    wlenc[i] = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      status = OUT;
      if (wlen > 0 && wlen <= MAXWORD)
        ++wlenc[wlen - 1];
      wlen = 0;
    } else {
      if (status == OUT)
        status = IN;
      ++wlen;
    }
  }
  for (int i = 0; i < MAXWORD; ++i) {
    printf("\n%2d: ", i + 1);
    for (int j = 0; j < wlenc[i]; ++j)
      printf("█");
    if (i != MAXWORD - 1)
      printf("\n |");
  }
  return EXIT_SUCCESS;
}

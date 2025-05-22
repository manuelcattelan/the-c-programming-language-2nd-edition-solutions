#include <stdio.h>
#include <stdlib.h>

/* Maximum amount of characters considered for a given line. This value should
 * account for the null character `\0` */
#define MAXLINE 1000

int readline(char line[]);
void revline(char line[], int llen);

int main(void) {
  int llen;           /* length of the current line being scanned */
  char line[MAXLINE]; /* content of the current line being scanned */
  while ((llen = readline(line)) > 0) {
    if (llen > 1)
      revline(line, llen);
    printf("%s", line);
  }
  return EXIT_SUCCESS;
}

int readline(char line[]) {
  int c;
  int cpos; /* position inside the current line being scanned */
  int llen; /* length of the current line being scanned */
  for (llen = cpos = 0; (c = getchar()) != EOF && c != '\n'; ++llen)
    if (llen < MAXLINE - 1)
      line[cpos++] = c;
  if (llen < MAXLINE - 1 && c == '\n') {
    line[cpos] = c;
    ++llen;
    ++cpos;
  }
  line[cpos] = '\0';
  return llen;
}

void revline(char line[], int llen) {
  int offset = line[llen - 1] == '\n' ? 1 : 0;
  for (int i = 0; i < (llen - offset) / 2; ++i) {
    char ctmp = line[i];
    line[i] = line[llen - 1 - i - offset];
    line[llen - 1 - i - offset] = ctmp;
  }
}

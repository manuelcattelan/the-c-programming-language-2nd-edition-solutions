#include <stdio.h>
#include <stdlib.h>

#define MINLINE 80 /* minimum length for a line to be printed */
/* Maximum amount of characters considered for a given line. This value should
 * account for the null character `\0` */
#define MAXLINE 1000

int readline(char line[]);

int main(void) {
  int llen;           /* length of the current line being scanned */
  char line[MAXLINE]; /* content of the current line being scanned */
  while ((llen = readline(line)) > 0)
    if (llen >= MINLINE)
      printf("%s", line);
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

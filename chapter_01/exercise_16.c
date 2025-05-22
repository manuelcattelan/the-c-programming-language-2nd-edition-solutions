#include <stdio.h>
#include <stdlib.h>

/* Maximum amount of characters considered for a given line. This value should
 * account for the null character `\0` */
#define MAXLINE 1000

int readline(char line[]);
void copyline(char from[], char to[]);

int main(void) {
  int llen;            /* length of the current line being scanned */
  int maxllen = 0;     /* length of the longest line scanned */
  char line[MAXLINE];  /* content of the current line being scanned */
  char lline[MAXLINE]; /* content of the longest line scanned */
  while ((llen = readline(line)) > 0)
    if (llen > maxllen) {
      maxllen = llen;
      copyline(line, lline);
    }
  if (maxllen > 0)
    printf("%d %s", maxllen, lline);
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

void copyline(char from[], char to[]) {
  for (int i = 0; (to[i] = from[i]) != '\0'; ++i)
    ;
}

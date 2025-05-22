#include <stdio.h>
#include <stdlib.h>

/* Maximum amount of characters considered for a given line. This value should
 * account for the null character `\0` */
#define MAXLINE 1000

int readline(char line[]);
int stripline(char line[], int llen);

int main(void) {
  int llen;           /* length of the current line being scanned */
  char line[MAXLINE]; /* content of the current line being scanned */
  while ((llen = readline(line)) > 0) {
    llen = stripline(line, llen);
    if (llen > 0 && line[0] != '\n')
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

int stripline(char line[], int llen) {
  /* This will be the position of the last non-blank, non-newline character
   * inside the line */
  int cpos;
  for (cpos = llen - 1; cpos >= 0 && (line[cpos] == '\n' || line[cpos] == ' ' ||
                                      line[cpos] == '\t');
       --cpos)
    ;
  if (line[llen - 1] == '\n')
    line[++cpos] = '\n';
  line[++cpos] = '\0';
  return cpos;
}

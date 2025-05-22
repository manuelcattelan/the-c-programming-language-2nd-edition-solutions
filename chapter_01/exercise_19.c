#include <stdio.h>
#include <stdlib.h>

/* Maximum amount of characters considered for a given line. This value should
 * account for the null character `\0` */
#define MAXLINE 1000

int readline(char line[]);
void reverse(char s[]);

int main(void) {
  int llen;           /* length of the current line being scanned */
  char line[MAXLINE]; /* content of the current line being scanned */
  while ((llen = readline(line)) > 0) {
    if (llen > 1)
      reverse(line);
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

void reverse(char s[]) {
  int llen;
  for (llen = 0; s[llen] != '\0'; ++llen)
    ;
  int offset = s[llen - 1] == '\n' ? 1 : 0;
  for (int i = 0; i < (llen - offset) / 2; ++i) {
    char ctmp = s[i];
    s[i] = s[llen - 1 - i - offset];
    s[llen - 1 - i - offset] = ctmp;
  }
}

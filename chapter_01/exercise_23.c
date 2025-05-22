#include <stdio.h>
#include <stdlib.h>

#define IN 1  /* state that represents being inside a string or comment */
#define OUT 0 /* state that represents being outside a string or comment */

int main(void) {
  int c;
  /* NOTE: there is no correct default value for the last seen character, but
   * EOF is a good representation of the fact that no valid character has been
   * read yet, making it a great choice for our usecase. */
  int lc = EOF;
  int sstatus = OUT; /* tracks if we're currently inside a string or not */
  int cstatus = OUT; /* tracks if we're currently inside a comment or not */
  while ((c = getchar()) != EOF) {
    if (sstatus == IN) {
      putchar(c);
      if ((c == '\'' || c == '\"') && lc != '\\')
        sstatus = OUT;
    } else {
      if (c == '\'' || c == '"') {
        putchar(c);
        sstatus = IN;
      } else if (c == '/' && lc == '/') {
        /* When we find two consecutive '/' characters, the only thing we do
         * is wait for the newline character to resume evaluating characters,
         * since that entire line will be a comment. */
        cstatus = IN;
        while ((c = getchar()) != EOF && c != '\n')
          ;
        if (c == '\n')
          putchar(c);
        cstatus = OUT;
      } else if (c == '*' && lc == '/') {
        /* When we find a `/` character followed by `*` character and assuming
         * the input is valid C syntax, the only thing we do is wait for the
         * closing `*` character followed by `/` character to resume evaluating
         * characters, since that entire line will be a comment. */
        cstatus = IN;
        while ((c = getchar()) != EOF && (c != '/' || lc != '*'))
          lc = c;
        /* Even if we could, we do not set `cstatus = OUT` immediately here as
         * we use it to understand if a possible trailing `/` was part of a
         * comment and thus should not be printed or if it was a single `/`,
         * which should be printed. */
      } else {
        /* Wait for what comes after a `/` before printing it when we first read
         * it and we haven't read another one before it, since we're not sure it
         * is going to be followed by another `/` and thus become a comment. */
        if (lc == '/' && cstatus == OUT)
          putchar('/');
        /* We print a single `/` character in the line above if it was not part
         * of a comment. */
        if (c != '/')
          putchar(c);
        cstatus = OUT;
      }
    }
    lc = c;
  }
  return EXIT_SUCCESS;
}

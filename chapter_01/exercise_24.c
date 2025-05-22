
#include <stdio.h>
#include <stdlib.h>

#define IN 1  /* state that represents being inside a string */
#define OUT 0 /* state that represents being outside a string */

int main(void) {
  int c;
  /* NOTE: there is no correct default value for the last seen character, but
   * EOF is a good representation of the fact that no valid character has been
   * read yet, making it a great choice for our usecase. */
  int lc = EOF;
  int status = OUT; /* tracks if we're currently inside a string or not */
  int np = 0;       /* balance count between opening and closing parenthesis */
  int nbk = 0;      /* balance count between opening and closing brackes */
  int nbr = 0;      /* balance count between opening and closing braces */
  while ((c = getchar()) != EOF) {
    if (status == IN) {
      if ((c == '\'' || c == '\"') && lc != '\\')
        status = OUT;
    } else {
      if (c == '\'' || c == '"') {
        status = IN;
      } else if (c == '/' && lc == '/') {
        while ((c = getchar()) != EOF && c != '\n')
          ;
      } else if (c == '*' && lc == '/') {
        while ((c = getchar()) != EOF && (c != '/' || lc != '*'))
          lc = c;
      } else {
        switch (c) {
          case '(':
            ++np;
            break;
          case ')':
            --np;
            break;
          case '[':
            ++nbk;
            break;
          case ']':
            --nbk;
            break;
          case '{':
            ++nbr;
            break;
          case '}':
            --nbr;
            break;
          default:
            break;
        }
      }
    }
    lc = c;
  }
  if (np != 0)
    printf("Unbalanced parenthesis!\n");
  if (nbk != 0)
    printf("Unbalanced brackes!\n");
  if (nbr != 0)
    printf("Unbalanced braces!\n");
  return EXIT_SUCCESS;
}

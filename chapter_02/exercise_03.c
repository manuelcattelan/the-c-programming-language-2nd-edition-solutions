#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int c;
  int cpos = 0; /* character position inside the current line */
  int lc = EOF; /* character read just before the current one */
  int dec = 0;  /* hexadecimal input converted to decimal output */
  while ((c = getchar()) != EOF && c != '\n') {
    /* An easy way to skip any initial 0x or 0X is to reset the output to 0
     * if we actually encounter this part. */
    if (lc == '0' && cpos == 1 && (c == 'x' || c == 'X'))
      dec = 0;
    ++cpos;
    if (isxdigit(c))
      /* If the character is a digit, it's equivalent integer value will be
       * computed as `c - '0'`, making use of the every machine's character set
       * that all digits form a contiguous increasing sequence inside it.
       * If the character is alphabetic, it is converted to its uppercase
       * equivalent (if already uppercase, nothing will actually happen) and
       * similarly to what we do for digits, we convert it to it's equivalent
       * number between 1 and 6 and add 10 so that the range becomes 10-16,
       * representing A-F. */
      dec = 16 * dec + (isdigit(c) ? c - '0' : toupper(c) - 'A' + 10);
    lc = c;
  }
  printf("%d\n", dec);
  return EXIT_SUCCESS;
}

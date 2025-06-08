#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int c;
  int c_pos = 0; /* character position inside the current line */
  /* NOTE: there is no correct default value for the previous character read,
   * but EOF is a good representation of the fact that no valid character has
   * been read yet. */
  int c_prev = EOF;
  int decimal = 0; /* hexadecimal input converted to decimal output */
  while ((c = getchar()) != EOF && c != '\n') {
    /* An easy way to skip any initial 0x or 0X is to reset the output to 0
     * if we actually encounter this part. */
    ++c_pos;
    if (c_prev == '0' && c_pos == 2 && (c == 'x' || c == 'X')) {
      decimal = 0;
    } else if (isxdigit(c)) {
      /* We do the computation in steps because we want to safely check for
       * overflow in the conversion to int. */
      if (decimal > INT_MAX / 16) {
        fprintf(stderr, "Integer overflow while converting input.\n");
        return EXIT_FAILURE;
      }
      int decimal_tmp = decimal * 16;
      int digit = isdigit(c) ? c - '0' : toupper(c) - 'A' + 10;
      if (decimal_tmp > INT_MAX - digit) {
        fprintf(stderr, "Integer overflow while converting input.\n");
        return EXIT_FAILURE;
      }
      /* If the character is a digit, it's equivalent integer value will be
       * computed as `c - '0'`, making use of the every machine's character set
       * that all digits form a contiguous increasing sequence inside it.
       * If the character is alphabetic, it is converted to its uppercase
       * equivalent (if already uppercase, nothing will actually happen) and
       * similarly to what we do for digits, we convert it to it's equivalent
       * number between 1 and 6 and add 10 so that the range becomes 10-16,
       * representing A-F. */
      decimal = decimal_tmp + digit;
    }
    c_prev = c;
  }
  printf("%d\n", decimal);
  return EXIT_SUCCESS;
}

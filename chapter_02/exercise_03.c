#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int c;
  int converted = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (isxdigit(c)) {
      if (converted > INT_MAX / 16) {
        fprintf(stderr, "Integer overflow while converting input.\n");
        return EXIT_FAILURE;
      }
      int converted_tmp = converted * 16;
      int converted_digit = isdigit(c) ? c - '0' : toupper(c) - 'A' + 10;
      if (converted_tmp > INT_MAX - converted_digit) {
        fprintf(stderr, "Integer overflow while converting input.\n");
        return EXIT_FAILURE;
      }
      converted = converted_tmp + converted_digit;
    }
  }
  printf("%d\n", converted);

  return EXIT_SUCCESS;
}

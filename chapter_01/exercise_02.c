#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("\a");
  printf("\b");
  printf("\f");
  printf("\n");
  printf("\r");
  printf("\t");
  printf("\v");
  printf("\\");
  printf("\'");
  printf("\"");
  printf("\?");
  printf("\377");
  printf("\xFF");
  printf("\uFFFF");
  printf("\U0000FFFF");
  return EXIT_SUCCESS;
}

/* When trying to print a string containing \c, where c is some character not
 * listed above, the compiler might issue a warning during compilation
 * indicating that the specified \c escape sequence is unknown.
 * Most compilers will handle such cases by simply printing the character c,
 * but the behavior is undefined according to the C standard. */

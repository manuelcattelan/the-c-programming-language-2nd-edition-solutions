#include <stdlib.h>

int main(void) {
  /* When trying to print \c, where c is some character that is not a known
   * escape sequence, the compiler might issue a warning during compilation
   * pointing to the issue. Most compilers will handle such cases by simply
   * printing the character c, but the behavior is undefined according to the C
   * standard. */
  return EXIT_SUCCESS;
}

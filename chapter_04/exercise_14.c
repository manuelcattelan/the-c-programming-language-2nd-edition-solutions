#include <stdlib.h>

/* The do-while pattern considered a standard when defining statement-like
 * macros because it allows the macro to behave exactly like a function call.
 * For example, this case would be problematic without the do-while pattern:
   if (condition)
    swap(int, a, b);  // Would expand to multiple statements
   else
    something_else();
 * Furthermore, parenthesis around variable names should also always be used
 * when arguments are used as values in the macro expansion, since they help
 * protect against operator precedence issues and ensure whatever expression
 * is passed gets evaluated as a single unit. */
#define swap(t, x, y)                                                          \
  do {                                                                         \
    t temp = (x);                                                              \
    (x) = (y);                                                                 \
    (y) = temp;                                                                \
  } while (0)

int main(void) { return EXIT_SUCCESS; }

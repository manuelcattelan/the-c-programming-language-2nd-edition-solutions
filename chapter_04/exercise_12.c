#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 1000

void integer_to_s_recursive_wrapper(int from, char to[]);

int main(void) {
  int from = 255;
  char to[MAX_STRING_LEN];

  integer_to_s_recursive_wrapper(from, to);
  printf("from: %d\nto: %s\n", from, to);

  return EXIT_SUCCESS;
}

int integer_to_s_recursive(int from, char to[], int i) {
  /* Base case: if from / 10 == 0 that means we're processing the last digit,
   * meaning we should handle it and return from the function. */
  if (from / 10 == 0) {
    to[i] = abs(from % 10) + '0';
    return i + 1;
  }

  /* Recursive case: process remaining digits by recursively call this function,
   * which returns the index where the next digit converted to character should
   * be inserted at. */
  i = integer_to_s_recursive(from / 10, to, i);

  /* Actual logic of the function, which converts an integer to its character
   * representation, using a bottom-up approach: we first recurse, reaching the
   * base case, then we perform the logic in a LIFO-like behavior. */
  to[i] = abs(from % 10) + '0';

  return i + 1;
}

/* We use a wrapper function to avoid having to define i as static and having to
 * reset it after each call to the recursive function. This approach also helps
 * us add the negative sign in the correct position when needed and to correctly
 * terminate the output string with the null terminator character. */
void integer_to_s_recursive_wrapper(int from, char to[]) {
  int i = 0;

  if (from < 0) {
    to[i++] = '-';
  }
  i = integer_to_s_recursive(from, to, i);
  to[i] = '\0';
}

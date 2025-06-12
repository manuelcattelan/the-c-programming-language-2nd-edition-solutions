#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_s_recursive_wrapper(char line[]);

int main(void) {
  char line[] = "dlrow ,olleh";

  printf("from: %s\n", line);
  reverse_s_recursive_wrapper(line);
  printf("to: %s\n", line);

  return EXIT_SUCCESS;
}

void reverse_s_recursive(char line[], int from, int to) {
  /* Base case: if from >= to that means the two indexes have crossed and
   * there's no more characters to swap in order to reverse the string, we can
   * simply return from the function. */
  if (from >= to) {
    return;
  }

  /* Actual logic of the function, which swaps the characters at both ends of
   * the given range, using a top-down approach: we first recurse, reaching the
   * base case, then we perform the logic in a FIFO-like behavior. */
  char c_tmp = line[from];
  line[from] = line[to];
  line[to] = c_tmp;

  /* Recursive case: process remaining characters by recursively call this
   * function with a narrower range, increasing the from index and decreasing
   * the to index. */
  reverse_s_recursive(line, from + 1, to - 1);
}

/* We use a wrapper function to avoid having to define the start and end of the
 * swap range as static and having to reset them after each call to the
 * recursive function. */
void reverse_s_recursive_wrapper(char line[]) {
  int line_len = strlen(line);

  if (line_len > 1) {
    reverse_s_recursive(line, 0, line_len - 1);
  }
}

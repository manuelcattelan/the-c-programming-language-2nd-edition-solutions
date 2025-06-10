#include <stdio.h>
#include <stdlib.h>

#define MIN_LINE_LEN 80 /* minimum length for an input line to be printed */
/* This threshold should take the null character \0 (used by terminating strings
 * correctly) into account, since we add it manually when reading each line. */
#define MAX_LINE_LEN 1000

int read_line(char line[]);

int main(void) {
  char line[MAX_LINE_LEN]; /* content of the current line being read */
  int line_len;            /* length of the current line being read */

  while ((line_len = read_line(line)) > 0) {
    if (line_len >= MIN_LINE_LEN) {
      printf("%s", line);
    }
  }

  return EXIT_SUCCESS;
}

int read_line(char line[]) {
  int c;
  /* Current position in the line array, which serves as index for storing
   * characters from the line being read. */
  int c_pos = 0;
  /* Actual length of the line being read, including characters that exceed the
   * array size. */
  int line_len = 0;

  /* The reason we don't stop reading the line after we exceed the array size is
   * that we want to prevent leftover characters from being interpreted as part
   * of the next line. */
  while ((c = getchar()) != EOF && c != '\n') {
    if (c_pos < MAX_LINE_LEN - 1) {
      line[c_pos++] = c;
    }
    ++line_len;
  }
  if (c == '\n') {
    /* Since we do not break out of the above for-loop when the length of the
     * line being scanned is greater than the maximum allowed, the check below
     * is essential in order to know if we can add the newline character we just
     * read into the line. */
    if (c_pos < MAX_LINE_LEN - 1) {
      line[c_pos++] = c;
    }
    ++line_len;
  }
  line[c_pos] = '\0';

  return line_len;
}

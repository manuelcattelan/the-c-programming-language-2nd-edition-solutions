#include <stdio.h>
#include <stdlib.h>

/* This threshold should take the null character \0 (used by terminating strings
 * correctly) into account, since we add it manually when reading each line. */
#define MAX_LINE_LEN 1000

int read_line(char line[]);
void reverse_line(char line[], int line_len);

int main(void) {
  char line[MAX_LINE_LEN]; /* content of the current line being read */
  int line_len;            /* length of the current line being read */

  while ((line_len = read_line(line)) > 0) {
    if (line_len > 1) {
      reverse_line(line, line_len);
    }
    printf("%s", line);
  }

  return EXIT_SUCCESS;
}

int read_line(char line[]) {
  int c;
  /* Current position in the line array, which serves as index for storing
   * characters from the line being read. */
  int c_pos = 0;

  /* The reason we don't stop reading the line after we exceed the array size is
   * that we want to prevent leftover characters from being interpreted as part
   * of the next line. */
  while ((c = getchar()) != EOF && c != '\n') {
    if (c_pos < MAX_LINE_LEN - 1) {
      line[c_pos++] = c;
    }
  }
  if (c == '\n') {
    /* Since we do not break out of the above for-loop when the length of the
     * line being scanned is greater than the maximum allowed, the check below
     * is essential in order to know if we can add the newline character we just
     * read into the line. */
    if (c_pos < MAX_LINE_LEN - 1) {
      line[c_pos++] = c;
    }
  }
  line[c_pos] = '\0';

  /* The reason we return the size of everything that fit into our line array
   * rather than the actual length of each input line is that this value is used
   * later by the reverse_line function in order to know the length of the line
   * without having to re-compute it. */
  return c_pos;
}

void reverse_line(char line[], int line_len) {
  /* Don't reverse the newline character but keep it at the end of the reversed
   * string by only considering characters from the start of the line up to the
   * last character before the newline character. */
  int right = line_len - 1;
  if (line[right] == '\n') {
    --right;
  }

  for (int left = 0; left < right; ++left, --right) {
    char c_tmp = line[left];
    line[left] = line[right];
    line[right] = c_tmp;
  }
}

#include <stdio.h>
#include <stdlib.h>

/* This threshold should take the null character \0 (used by terminating strings
 * correctly) into account, since we add it manually when reading each line. */
#define MAX_LINE_LEN 1000

int read_line(char line[]);
void copy_line(const char from[], char to[]);

int main(void) {
  char line[MAX_LINE_LEN];         /* content of the current line being read */
  char longest_line[MAX_LINE_LEN]; /* content of the longest line read */
  int line_len;                    /* length of the current line being read */
  int longest_line_len = 0;        /* length of the longest line read */

  while ((line_len = read_line(line)) > 0) {
    if (line_len > longest_line_len) {
      longest_line_len = line_len;
      copy_line(line, longest_line);
    }
  }

  if (longest_line_len > 0) {
    printf("The length of the longest line was %d "
           "and here's its content: %s",
           longest_line_len, longest_line);
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
   * that we want the real length of the line, and not just the length of
   * whatever we were able to store in the line array. */
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

void copy_line(const char from[], char to[]) {
  for (int i = 0; (to[i] = from[i]) != '\0'; ++i) {
    ;
  }
}

#include <stdio.h>
#include <stdlib.h>

#define MIN_LINE_LEN 80 /* minimum length for a line to be printed */
/* Maximum number of characters to be considered for each line that we read from
 * input, which should also take into account for the null character \0 used by
 * terminating strings correctly. */
#define MAX_LINE_LEN 1000

int read_line(char line[]);

int main(void) {
  char line[MAX_LINE_LEN]; /* content of the current line being scanned */
  int line_len;            /* length of the current line being scanned */
  while ((line_len = read_line(line)) > 0) {
    if (line_len >= MIN_LINE_LEN) {
      printf("%s", line);
    }
  }
  return EXIT_SUCCESS;
}

int read_line(char line[]) {
  int c;
  /* This variable keeps track of the character position inside the characters
   * array that we use to store characters from input, since we still want to
   * consume the entirety of each line, even if it is too long to be stored in
   * our variable. */
  int c_pos = 0;
  int line_len = 0; /* length of the current line being scanned */
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

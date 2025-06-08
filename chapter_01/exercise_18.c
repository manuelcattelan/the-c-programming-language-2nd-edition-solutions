#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum number of characters to be considered for each line that we read from
 * input, which should also take into account for the null character \0 used by
 * terminating strings correctly. */
#define MAX_LINE_LEN 1000

int read_line(char line[]);
int strip_line(char line[], int line_len);

int main(void) {
  char line[MAX_LINE_LEN]; /* content of the current line being scanned */
  int line_len;            /* length of the current line being scanned */
  while ((line_len = read_line(line)) > 0) {
    line_len = strip_line(line, line_len);
    if (line_len > 0 && line[0] != '\n') {
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
  /* We return c_pos which is not the actual length of each input line but
   * rather the size of everything that fit into our characters array because it
   * is used later by the strip_line function in order to know the length of the
   * string without having to re-compute it. */
  return c_pos;
}

int strip_line(char line[], int line_len) {
  if (line_len <= 0) {
    return 0;
  }
  /* We loop over the characters of the line from the end by consuming each
   * character that returns true from isspace(c) while also decrementing c_pos
   * so that it will point to the last non-space character in the line after the
   * loop breaks. */
  int c_pos = line_len - 1;
  for (; c_pos >= 0 && (isspace(line[c_pos])); --c_pos) {
    ;
  }
  /* If the last character inside the original line was a newline character, we
   * add it back to the string at the end of it. */
  if (line[line_len - 1] == '\n') {
    line[++c_pos] = '\n';
  }
  line[++c_pos] = '\0';
  /* Since c_pos is a 0-based index and we want the actual length of the line to
   * be returned from the function, we do not return c_pos - 1 even if c_pos
   * points to the null character \0. */
  return c_pos;
}

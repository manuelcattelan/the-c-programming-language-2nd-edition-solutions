#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximum number of characters to be considered for each line that we read from
 * input, which should also take into account for the null character \0 used by
 * terminating strings correctly. */
#define MAX_LINE_LEN 1000

int read_line(char line[]);
void reverse(char s[]);

int main(void) {
  char line[MAX_LINE_LEN]; /* content of the current line being scanned */
  int line_len;            /* length of the current line being scanned */
  while ((line_len = read_line(line)) > 0) {
    if (line_len > 1) {
      reverse(line);
    }
    printf("%s", line);
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

void reverse(char s[]) {
  int line_len = strlen(s);
  /* Don't reverse the newline character but keep it at the end of the reversed
   * string by only considering characters from the start of the string up to
   * the last one before the newline character. */
  int offset = s[line_len - 1] == '\n' ? 1 : 0;
  for (int i = 0; i < (line_len - offset) / 2; ++i) {
    char c_tmp = s[i];
    s[i] = s[line_len - 1 - i - offset];
    s[line_len - 1 - i - offset] = c_tmp;
  }
}

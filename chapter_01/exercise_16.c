#include <stdio.h>
#include <stdlib.h>

/* Maximum number of characters to be considered for each line that we read from
 * input, which should also take into account for the null character \0 used by
 * terminating strings correctly. */
#define MAX_LINE_LEN 1000

int read_line(char line[]);
void copy_line(const char from[], char to[]);

int main(void) {
  char line[MAX_LINE_LEN]; /* content of the current line being scanned */
  char longest_line[MAX_LINE_LEN]; /* content of the longest line scanned */
  int line_len;             /* length of the current line being scanned */
  int longest_line_len = 0; /* length of the longest line scanned */
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
  /* This variable keeps track of the character position inside the characters
   * array that we use to store characters from input, since we want to store
   * as much as possible of the input line while also tracking it's actual
   * length. */
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

void copy_line(const char from[], char to[]) {
  for (int i = 0; (to[i] = from[i]) != '\0'; ++i) {
    ;
  }
}

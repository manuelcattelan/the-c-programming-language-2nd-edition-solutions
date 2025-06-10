#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  /* Status that represents being outside a string or character constant */
  OUTSIDE,
  /* Status that represents being inside a string or character constant  */
  INSIDE
} Status;

int main(void) {
  int c;
  /* Track escape state to properly handle scenarios like consecutive
   * backslashes. Without this flag, cases like "hello, world\\" would be
   * mishandled and the last " character would be interpreted as escaped. */
  bool is_escaped = false;
  /* Track slash state for comment detection so that we can determine if a '/'
   * or '*' character is the start of a single-line or multi-line comment. */
  bool is_comment_start = false;
  Status c_status = OUTSIDE; /* if we're inside a character constant or not */
  Status s_status = OUTSIDE; /* if we're inside a string or not */

  while ((c = getchar()) != EOF) {
    if (c_status == INSIDE) {
      putchar(c);
      if (c == '\'' && !is_escaped) {
        c_status = OUTSIDE;
      }
      is_escaped = (c == '\\' && !is_escaped);
    } else if (s_status == INSIDE) {
      putchar(c);
      if (c == '"' && !is_escaped) {
        s_status = OUTSIDE;
      }
      is_escaped = (c == '\\' && !is_escaped);
    } else {
      if (c == '\'') {
        putchar(c);
        c_status = INSIDE;
      } else if (c == '\"') {
        putchar(c);
        s_status = INSIDE;
      } else if (c == '/') {
        if (is_comment_start) {
          while ((c = getchar()) != EOF && c != '\n') {
            ;
          }
          is_comment_start = false;
        } else {
          is_comment_start = true;
        }
      } else if (c == '*') {
        if (is_comment_start) {
          /* There is no correct default value for the previous character read,
           * but EOF is a good representation of the fact that no valid
           * character has been read yet. */
          int c_prev = EOF;
          while ((c = getchar()) != EOF && !(c == '/' && c_prev == '*')) {
            c_prev = c;
          }
          is_comment_start = false;
        } else {
          putchar(c);
        }
      } else {
        /* If the previous character we encountered was a / and it was not part
         * of a comment, we should flush it now, before the one we've just
         * consumed. */
        if (is_comment_start) {
          putchar('/');
          is_comment_start = false;
        }
        putchar(c);
      }
      is_escaped = false;
    }
  }
  /* If the input ends with a / character, it should be flushed at the end of
   * execution. */
  if (is_comment_start) {
    putchar('/');
    is_comment_start = false;
  }

  return EXIT_SUCCESS;
}

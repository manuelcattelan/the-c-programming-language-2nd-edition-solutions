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
  int num_paren = 0; /* balance count between opening and closing parenthesis */
  int num_brackets = 0; /* balance count between opening and closing brackets */
  int num_braces = 0;   /* balance count between opening and closing braces */

  while ((c = getchar()) != EOF) {
    if (c_status == INSIDE) {
      if (c == '\'' && !is_escaped) {
        c_status = OUTSIDE;
      }
      is_escaped = (c == '\\' && !is_escaped);
    } else if (s_status == INSIDE) {
      if (c == '"' && !is_escaped) {
        s_status = OUTSIDE;
      }
      is_escaped = (c == '\\' && !is_escaped);
    } else {
      if (c == '\'') {
        c_status = INSIDE;
      } else if (c == '\"') {
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
        }
      } else {
        switch (c) {
          case '(':
            ++num_paren;
            break;
          case ')':
            --num_paren;
            break;
          case '[':
            ++num_brackets;
            break;
          case ']':
            --num_brackets;
            break;
          case '{':
            ++num_braces;
            break;
          case '}':
            --num_braces;
            break;
          default:
            break;
        }
      }
      is_escaped = false;
    }
  }

  if (num_paren != 0) {
    printf("Unbalanced parenthesis!\n");
  }
  if (num_brackets != 0) {
    printf("Unbalanced brackets!\n");
  }
  if (num_braces != 0) {
    printf("Unbalanced braces!\n");
  }

  return EXIT_SUCCESS;
}

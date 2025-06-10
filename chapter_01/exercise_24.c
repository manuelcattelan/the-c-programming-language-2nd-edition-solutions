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
  /* There is no correct default value for the previous character read,
   * but EOF is a good representation of the fact that no valid character has
   * been read yet. */
  int c_prev = EOF;
  /* We use a dedicated variable to check if we're escaping the current
   * character instead of exploiting c_prev for a single reason: without it,
   * we're unable to handle double consecutive backslashes, such as in
   * "hello, world\\", in which case, without is_escaped, the last '"' character
   * would be interpreted as an escape sequence. */
  bool is_escaped = false;
  /* Track if we've consumed a / which could result in a comment based on what
   * character follows next. In case another / or a * follow, that would be the
   * beginning of a comment, otherwise we should print the previously consumed
   * single / and the new character. */
  bool is_comment_start = false;
  Status c_status = OUTSIDE; /* if we're inside a character constant or not */
  Status s_status = OUTSIDE; /* if we're inside a string or not */
  int num_paren = 0; /* balance count between opening and closing parenthesis */
  int num_brackets = 0; /* balance count between opening and closing brackets */
  int num_braces = 0;   /* balance count between opening and closing braces */

  while ((c = getchar()) != EOF) {
    if (c_status == INSIDE) {
      /* If we find the closing ' character and it is not escaped, that marks
       * the end of our character constant. */
      if (c == '\'' && !is_escaped) {
        c_status = OUTSIDE;
      }
      is_escaped = (c == '\\' && !is_escaped);
    } else if (s_status == INSIDE) {
      /* If we find the closing " character and it is not escaped, that marks
       * the end of our string. */
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
          /* Wait till the end of the line so that the comment ends. */
          while ((c = getchar()) != EOF && c != '\n') {
            ;
          }
          is_comment_start = false;
        } else {
          /* We keep track of the fact that we've encountered a / character
           * which could result in a comment depending on the character consumed
           * after the current one. */
          is_comment_start = true;
        }
      } else if (c == '*') {
        if (is_comment_start) {
          /* Wait till we find the matching comment characters so that the
           * comment ends. */
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
      c_prev = c;
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

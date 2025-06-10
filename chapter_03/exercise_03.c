#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000

void expand_s_patterns(char from[], char to[]);

int main(void) {
  char s_to_expand[MAX_STRING_LEN] = "a-z";
  /* The length of s2 takes into consideration that the worst case scenario (the
   * one that causes s2 to be the longest) is the one in which s1 is composed
   * of consecutive sequences of a-z substrings. In this case, since the last
   * character of s1 is the null character \0, there can be at most (MAXLEN - 1)
   * / 3 a-z patterns (3 is the number of characters in "a-z"). Each pattern
   * expands to a substring of 26 characters and we should make up space for
   * terminating the string with the null character \0. */
  char s_expanded[(MAX_STRING_LEN - 1) / 3 * 26 + 1];

  expand_s_patterns(s_to_expand, s_expanded);
  printf("s_to_expand: %s\ns_expanded: %s\n", s_to_expand, s_expanded);

  return EXIT_SUCCESS;
}

void expand_s_patterns(char from[], char to[]) {
  int c_pos = 0;
  int from_len = strlen(from);

  for (int i = 0; i < from_len;) {
    /* If there's enough space for a valid pattern ahead of us and it is
     * actually present and valid, we expand it. */
    if (i + 2 < from_len && from[i + 1] == '-' &&
        ((isdigit(from[i]) && isdigit(from[i + 2])) ||
         (islower(from[i]) && islower(from[i + 2])) ||
         (isupper(from[i]) && isupper(from[i + 2])))) {
      char pattern_start = from[i];
      char pattern_end = from[i + 2];
      if (pattern_start <= pattern_end) {
        for (char c = pattern_start; c <= pattern_end; c++) {
          to[c_pos++] = c;
        }
      } else {
        for (char c = pattern_start; c >= pattern_end; c--) {
          to[c_pos++] = c;
        }
      }
      /* Since all patterns are composed of 3 characters (from-to), once we
       * expand a pattern we simply move forward by 3 to consume the first
       * character after the pattern we just expanded. */
      i += 3;
    } else {
      to[c_pos++] = from[i];
      i++;
    }
  }
  to[c_pos] = '\0';
}

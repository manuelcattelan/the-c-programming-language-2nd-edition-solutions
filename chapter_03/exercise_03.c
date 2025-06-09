#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000

void expand(char s1[], char s2[]);

int main(void) {
  char s1[MAX_STRING_LEN] = "a-z";
  /* The length of s2 takes into consideration that the worst case scenario (the
   * one that causes s2 to be the longest) is the one in which s1 is composed
   * of consecutive sequences of a-z substrings. In this case, since the last
   * character of s1 is the null character \0, there can be at most (MAXLEN - 1)
   * / 3 a-z patterns (3 is the number of characters in "a-z"). Each pattern
   * expands to a substring of 26 characters and we should make up space for
   * terminating the string with the null character \0. */
  char s1_expanded[(MAX_STRING_LEN - 1) / 3 * 26 + 1];
  expand(s1, s1_expanded);
  printf("s1: %s\ns2: %s\n", s1, s1_expanded);
  return EXIT_SUCCESS;
}

void expand(char from[], char to[]) {
  int from_idx = 0;
  int to_idx = 0;
  int from_len = strlen(from);
  while (from_idx < from_len) {
    /* If there's enough space for a valid pattern ahead of us and it is
     * actually present and valid, we expand it. */
    if (from_idx + 2 < from_len && from[from_idx + 1] == '-' &&
        ((isdigit(from[from_idx]) && isdigit(from[from_idx + 2])) ||
         (islower(from[from_idx]) && islower(from[from_idx + 2])) ||
         (isupper(from[from_idx]) && isupper(from[from_idx + 2])))) {
      char pattern_start = from[from_idx];
      char pattern_end = from[from_idx + 2];
      if (pattern_start <= pattern_end) {
        for (char c = pattern_start; c <= pattern_end; c++) {
          to[to_idx++] = c;
        }
      } else {
        for (char c = pattern_start; c >= pattern_end; c--) {
          to[to_idx++] = c;
        }
      }
      /* Since all patterns are composed of 3 characters (from-to), once we
       * expand a pattern we simply move forward by 3 to consume the first
       * character after the pattern we just expanded. */
      from_idx += 3;
    } else {
      to[to_idx++] = from[from_idx];
      from_idx++;
    }
  }
  to[to_idx] = '\0';
}

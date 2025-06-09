#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 1000

void escape(const char from[], char to[]);
void unescape(const char from[], char to[]);

int main(void) {
  char s1[MAX_STRING_LEN] =
      "This string contains both a newline \n and a tab \t.";
  /* The length of t1 should take into consideration that at most MAXLEN - 1
   * characters of s1 may be newlines or tabs, since the last one is always
   * the null character \0 for terminating the string. For that reason, since
   * we're converting 1-byte characters (\n and \t are considered single
   * characters) to 2-byte ones (their visible representation), we should
   * multiply the length of the starting string s1 by 2 and make space for the
   * null character too. */
  char s1_escaped[(MAX_STRING_LEN - 1) * 2 + 1];
  char s2[MAX_STRING_LEN] =
      "This string contains both a newline \\n and a tab \\t.";
  /* The length of t2 should take into consideration that we're going from the
   * visible representation of newline and tab characters to the actual
   * characters (\n and \t), hence it will be at most the same as the length of
   * s2 because we're converting any potential "\\n" and "\\t" into their 1-byte
   * character representation. */
  char s2_unescaped[MAX_STRING_LEN];
  escape(s1, s1_escaped);
  printf("s1: %s\nt1: %s\n", s1, s1_escaped);
  unescape(s2, s2_unescaped);
  printf("s2: %s\nt2: %s\n", s2, s2_unescaped);
  return EXIT_SUCCESS;
}

void escape(const char from[], char to[]) {
  int to_idx = 0;
  for (int from_idx = 0; from[from_idx] != '\0'; ++from_idx) {
    switch (from[from_idx]) {
      case '\n':
        to[to_idx++] = '\\';
        to[to_idx++] = 'n';
        break;
      case '\t':
        to[to_idx++] = '\\';
        to[to_idx++] = 't';
        break;
      default:
        to[to_idx++] = from[from_idx];
        break;
    }
  }
  to[to_idx] = '\0';
}

void unescape(const char from[], char to[]) {
  int from_idx = 0;
  int to_idx = 0;
  /* We use a dedicated variable to check if we're escaping the current
   * character instead of exploiting c_prev for a single reason: without it,
   * we're unable to handle double consecutive backslashes, such as in
   * "hello, world\\", in which case, without is_escaped, the last '"' character
   * would be interpreted as an escape sequence. */
  bool is_escaped = false;
  while (from[from_idx] != '\0') {
    char c = from[from_idx];
    if (is_escaped) {
      switch (c) {
        case 'n':
          to[to_idx++] = '\n';
          break;
        case 't':
          to[to_idx++] = '\t';
          break;
        default:
          to[to_idx++] = '\\';
          to[to_idx++] = c;
          break;
      }
    } else if (c != '\\') {
      to[to_idx++] = c;
    }
    is_escaped = (c == '\\' && !is_escaped);
    from_idx++;
  }
  if (is_escaped) {
    to[to_idx++] = '\\';
  }
  to[to_idx] = '\0';
}

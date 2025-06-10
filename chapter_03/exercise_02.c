#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 1000

void escape_s(const char from[], char to[]);
void unescape_s(const char from[], char to[]);

int main(void) {
  char s_to_escape[MAX_STRING_LEN] =
      "This string contains both a newline \n and a tab \t.";
  /* The length of t1 should take into consideration that at most MAXLEN - 1
   * characters of s1 may be newlines or tabs, since the last one is always
   * the null character \0 for terminating the string. For that reason, since
   * we're converting 1-byte characters (\n and \t are considered single
   * characters) to 2-byte ones (their visible representation), we should
   * multiply the length of the starting string s1 by 2 and make space for the
   * null character too. */
  char s_escaped[(MAX_STRING_LEN - 1) * 2 + 1];
  char s_to_unescape[MAX_STRING_LEN] =
      "This string contains both a newline \\n and a tab \\t.";
  /* The length of t2 should take into consideration that we're going from the
   * visible representation of newline and tab characters to the actual
   * characters (\n and \t), hence it will be at most the same as the length of
   * s2 because we're converting any potential "\\n" and "\\t" into their 1-byte
   * character representation. */
  char s_unescaped[MAX_STRING_LEN];

  escape_s(s_to_escape, s_escaped);
  printf("s1: %s\nt1: %s\n", s_to_escape, s_escaped);

  unescape_s(s_to_unescape, s_unescaped);
  printf("s2: %s\nt2: %s\n", s_to_unescape, s_unescaped);

  return EXIT_SUCCESS;
}

void escape_s(const char from[], char to[]) {
  int c_pos = 0;

  for (int i = 0; from[i] != '\0'; ++i) {
    switch (from[i]) {
      case '\n':
        to[c_pos++] = '\\';
        to[c_pos++] = 'n';
        break;
      case '\t':
        to[c_pos++] = '\\';
        to[c_pos++] = 't';
        break;
      default:
        to[c_pos++] = from[i];
        break;
    }
  }
  to[c_pos] = '\0';
}

void unescape_s(const char from[], char to[]) {
  int c_pos = 0;
  /* Track escape state to properly handle scenarios like consecutive
   * backslashes. Without this flag, cases like "hello, world\\" would be
   * mishandled and the last " character would be interpreted as escaped. */
  bool is_escaped = false;

  for (int i = 0; from[i] != '\0'; i++) {
    char c = from[i];
    if (is_escaped) {
      switch (c) {
        case 'n':
          to[c_pos++] = '\n';
          break;
        case 't':
          to[c_pos++] = '\t';
          break;
        default:
          to[c_pos++] = '\\';
          to[c_pos++] = c;
          break;
      }
      is_escaped = false;
    } else if (c == '\\') {
      is_escaped = true;
    } else {
      to[c_pos++] = c;
    }
  }
  if (is_escaped) {
    to[c_pos++] = '\\';
  }
  to[c_pos] = '\0';
}

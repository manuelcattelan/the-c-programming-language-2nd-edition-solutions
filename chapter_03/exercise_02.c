#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000 /* maximum length for starting string */

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void) {
  char s1[MAXLEN] = "This string contains both a newline \n and a tab \t.";
  /* The length of t1 should take into consideration that at most MAXLEN - 1
   * characters of s1 may be newlines or tabs, since the last one is always
   * the null character \0 for terminating the string. For that reason, since
   * we're converting 1-byte characters (\n and \t are considered single
   * characters) to 2-byte ones (their visible representation), we should
   * multiply the length of the starting string s1 by 2 and make space for the
   * null character too. */
  char t1[(MAXLEN - 1) * 2 + 1];
  char s2[MAXLEN] = "This string contains both a newline \\n and a tab \\t.";
  /* The length of t2 should take into consideration that we're going from the
   * visible representation of newline and tab characters to the actual
   * characters (\n and \t), hence it will be at most the same as the length of
   * s2 because we're converting any potential "\\n" and "\\t" into their 1-byte
   * character representation. */
  char t2[MAXLEN];
  escape(s1, t1);
  printf("s1: %s\nt1: %s\n", s1, t1);
  unescape(s2, t2);
  printf("s2: %s\nt2: %s\n", s2, t2);
  return EXIT_SUCCESS;
}

void escape(char s[], char t[]) {
  int j = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    switch (s[i]) {
      case '\n':
        t[j++] = '\\';
        t[j++] = 'n';
        break;
      case '\t':
        t[j++] = '\\';
        t[j++] = 't';
        break;
      default:
        t[j++] = s[i];
        break;
    }
  }
  t[j] = '\0';
}

void unescape(char s[], char t[]) {
  int lc = EOF;
  int i = 0;
  int j = 0;
  while (s[i] != '\0') {
    if (s[i] != '\\') {
      if (lc == '\\') {
        switch (s[i]) {
          case 'n':
            t[j++] = '\n';
            break;
          case 't':
            t[j++] = '\t';
            break;
          default:
            t[j++] = '\\';
            t[j++] = s[i];
            break;
        }
      } else
        t[j++] = s[i];
    }
    lc = s[i++];
  }
}

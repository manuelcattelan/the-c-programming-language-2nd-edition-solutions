#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000 /* maximum length for starting string */

void expand(char s1[], char s2[]);

int main(void) {
  char s1[MAXLEN] = "a-z";
  /* The length of s2 takes into consideration that the worst case scenario (the
   * one that causes s2 to be the longest) is the one in which s1 is composed
   * of consecutive sequences of a-z substrings. In this case, since the last
   * character of s1 is the null character \0, the can be at most (MAXLEN - 1) /
   * 3 a-z patterns (3 is the number of characters in "a-z"). Each pattern
   * expands to a substring of 26 characters and we should make up space for
   * terminating the string with the null character \0. */
  char s2[(MAXLEN - 1) / 3 * 26 + 1];
  expand(s1, s2);
  printf("s1: %s\ns2: %s\n", s1, s2);
  return EXIT_SUCCESS;
}

void expand(char s1[], char s2[]) {
  int lc = EOF;  /* character read just before the current one */
  int slc = EOF; /* character read just before the last one */
  unsigned long i, j;
  for (i = j = 0; i < strlen(s1); ++i) {
    if ((i == 0 || i == strlen(s1) - 1) && s1[i] == '-')
      s2[j++] = s1[i];
    else {
      if (lc == '-') {
        if (((isdigit(s1[i]) && isdigit(slc)) ||
             (islower(s1[i]) && islower(slc)) ||
             (isupper(s1[i]) && isupper(slc))) &&
            s1[i] != slc) {
          if (s1[i] > slc)
            for (int z = 0; z < s1[i] - slc; ++z)
              s2[j++] = slc + z + 1;
          else
            for (int z = 0; z < slc - s1[i]; ++z)
              s2[j++] = slc - z - 1;
        } else if (s1[i] != slc)
          s2[j++] = s1[i];
      } else if (s1[i] != '-' ||
                 (s1[i] == '-' && ((isdigit(lc) && !isdigit(s1[i + 1])) ||
                                   (!isdigit(lc) && isdigit(s1[i + 1])) ||
                                   (!islower(lc) && islower(s1[i + 1])) ||
                                   (islower(lc) && !islower(s1[i + 1])) ||
                                   (isupper(lc) && !isupper(s1[i + 1])) ||
                                   (!isupper(lc) && isupper(s1[i + 1])))))
        s2[j++] = s1[i];
    }
    if (i != 0)
      slc = lc;
    lc = s1[i];
  }
  s2[j] = '\0';
}

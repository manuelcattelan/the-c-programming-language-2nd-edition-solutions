#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000 /* maximum length for starting string */

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void) {
  int n = 153;
  char s[MAXLEN];
  itoa(n, s);
  printf("n: %d\ns: %s\n", n, s);
  return EXIT_SUCCESS;
}

void itoa(int n, char s[]) {
  int i = 0;
  int si = n;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);
  if (si < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int llen;
  for (llen = 0; s[llen] != '\0'; ++llen)
    ;
  int off = s[llen - 1] == '\n' ? 1 : 0;
  for (int i = 0; i < (llen - off) / 2; ++i) {
    char ctmp = s[i];
    s[i] = s[llen - 1 - i - off];
    s[llen - 1 - i - off] = ctmp;
  }
}

/* The original solution didn't handle the largest negative number
 * (whose value is machine-dependent) as it tried to negate n when negative. The
 * issue is that the value range for a signed integer is between
 * -(2^(wordsize-1)) to (2^(wordsize-1)) - 1, which means that when trying to
 * negate the largest negative number by simply inverting its sign we would
 * cause an overflow.*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000 /* maximum length for starting string */

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void) {
  int n = -178;
  char s[MAXLEN];
  itob(n, s, 8);
  printf("n: %d\ns: %s\n", n, s);
  itob(n, s, 10);
  printf("n: %d\ns: %s\n", n, s);
  itob(n, s, 16);
  printf("n: %d\ns: %s\n", n, s);
  return EXIT_SUCCESS;
}

void itob(int n, char s[], int b) {
  int i = 0;
  int si = n;
  do {
    int sn = abs(n % b);
    if (sn >= 10)
      sn += 'A' - 10;
    else
      sn += '0';
    s[i++] = sn;
  } while ((n /= b) != 0);
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

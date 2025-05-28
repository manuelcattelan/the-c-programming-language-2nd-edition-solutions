#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000 /* maximum length for starting string */

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void) {
  int n = 255;
  int w = 8;
  char s[MAXLEN];
  itoa(n, s, w);
  printf("n: %d\nw: %d\ns: %s\n", n, w, s);
  return EXIT_SUCCESS;
}

void itoa(int n, char s[], int w) {
  int i = 0;
  int si = n;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);
  if (si < 0)
    s[i++] = '-';
  s[i] = '\0';
  int sl = strlen(s);
  if (si < 0)
    sl -= 1;
  if (sl < w) {
    int j = sl;
    int ml = (si < 0) ? MAXLEN - 1 : MAXLEN;
    for (; j < ml && j < w; ++j)
      s[j] = '0';
    if (si < 0)
      s[j++] = '-';
    s[j] = '\0';
  }
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

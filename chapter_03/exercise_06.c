#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void) {
  int n = 255;
  int min_width = 8;
  char s[MAX_STRING_LEN];
  itoa(n, s, min_width);
  printf("n: %d\nw: %d\ns: %s\n", n, min_width, s);
  return EXIT_SUCCESS;
}

void itoa(int n, char s[], int w) {
  int i = 0;
  int i_sign = n;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);
  if (i_sign < 0) {
    s[i++] = '-';
  }
  while (i < w) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int s_len = strlen(s);
  for (int i = 0; i < s_len / 2; ++i) {
    char c_tmp = s[i];
    s[i] = s[s_len - 1 - i];
    s[s_len - 1 - i] = c_tmp;
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void) {
  int n = 255;
  char s[MAX_STRING_LEN];
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
  int i_sign = n;
  do {
    int n_converted = abs(n % b);
    if (n_converted >= 10) {
      n_converted += 'A' - 10;
    } else {
      n_converted += '0';
    }
    s[i++] = n_converted;
  } while ((n /= b) != 0);
  if (i_sign < 0) {
    s[i++] = '-';
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

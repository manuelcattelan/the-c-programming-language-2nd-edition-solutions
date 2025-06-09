#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void) {
  int n = 255;
  char s[MAX_STRING_LEN];
  itoa(n, s);
  printf("n: %d\ns: %s\n", n, s);
  return EXIT_SUCCESS;
}

void itoa(int n, char s[]) {
  int i = 0;
  /* This is the most important part of the program, which avoids overflow in
   * the original program when trying to negate the largest negative number. In
   * this case, instead of negating n directly, we use the abs function below
   * and add the sign manually, if needed. */
  int i_sign = n;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);
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

/* The original solution didn't handle the largest negative number
 * (whose value is machine-dependent) as it tried to negate n when negative. The
 * issue is that the value range for a signed integer is between
 * -(2^(wordsize-1)) to (2^(wordsize-1)) - 1, which means that when trying to
 * negate the largest negative number by simply inverting its sign we would
 * cause an overflow. */

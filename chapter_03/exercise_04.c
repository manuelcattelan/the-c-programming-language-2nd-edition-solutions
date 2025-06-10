#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000

void integer_to_s(int from, char to[]);
void reverse_s(char s[]);

int main(void) {
  int from = 255;
  char to[MAX_STRING_LEN];

  integer_to_s(from, to);
  printf("from: %d\nto: %s\n", from, to);

  return EXIT_SUCCESS;
}

void integer_to_s(int from, char to[]) {
  int i = 0;
  /* Do not negate from directly at the beginning since it could lead to
   * overflow, if from is the largest negative integer INT_MIN. */
  int sign = from;

  do {
    /* The conversion happens by getting the last digit of from using the modulo
     * operator with absolute value (to handle negative numbers correctly) and
     * by adding '0' to the result in order to convert the digit to its
     * corresponding character. */
    to[i++] = abs(from % 10) + '0';
    /* At each iteration, we divide from by 10 to remove the last digit (the
     * one we have just handled) until from is non-0. */
  } while ((from /= 10) != 0);
  if (sign < 0) {
    to[i++] = '-';
  }
  to[i] = '\0';

  reverse_s(to);
}

void reverse_s(char s[]) {
  int right = strlen(s) - 1;

  for (int left = 0; left < right; ++left, --right) {
    char c_tmp = s[left];
    s[left] = s[right];
    s[right] = c_tmp;
  }
}

/* The original solution didn't handle the largest negative number
 * (whose value is machine-dependent) as it tried to negate n when negative. The
 * issue is that the value range for a signed integer is between
 * -(2^(wordsize-1)) to (2^(wordsize-1)) - 1, which means that when trying to
 * negate the largest negative number by simply inverting its sign we would
 * cause an overflow. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000

void integer_to_s_with_base(int from, char to[], int base);
void reverse_s(char s[]);

int main(void) {
  int from = 255;
  char to[MAX_STRING_LEN];
  int base;

  base = 8;
  integer_to_s_with_base(from, to, base);
  printf("from: %d\nbase: %d\nto: %s\n", from, base, to);

  base = 10;
  integer_to_s_with_base(from, to, base);
  printf("from: %d\nbase: %d\nto: %s\n", from, base, to);

  base = 16;
  integer_to_s_with_base(from, to, base);
  printf("from: %d\nbase: %d\nto: %s\n", from, base, to);

  return EXIT_SUCCESS;
}

void integer_to_s_with_base(int from, char to[], int base) {
  int i = 0;
  /* Do not negate from directly at the beginning since it could lead to
   * overflow, if from is the largest negative integer INT_MIN. */
  int sign = from;

  do {
    /* The conversion happens by getting the last digit of from using the modulo
     * operator with absolute value (to handle negative numbers correctly) and
     * by adding '0' or ('A' - 10) to the result in order to convert the digit
     * to its corresponding character. */
    int from_converted = abs(from % base);
    if (from_converted >= 10) {
      from_converted += 'A' - 10;
    } else {
      from_converted += '0';
    }
    to[i++] = from_converted;
    /* At each iteration, we divide from by base to remove the last digit (the
     * one we have just handled) until from is non-0. */
  } while ((from /= base) != 0);
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

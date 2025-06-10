#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000

void integer_to_s_with_min_width(int from, char to[], int min_width);
void reverse_s(char s[]);

int main(void) {
  int from = 255;
  char to[MAX_STRING_LEN];
  int min_width = 8;

  integer_to_s_with_min_width(from, to, min_width);
  printf("from: %d\nmin_width: %d\nto: %s\n", from, min_width, to);

  return EXIT_SUCCESS;
}

void integer_to_s_with_min_width(int from, char to[], int min_width) {
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
  /* If the resulting string isn't long enough, tab it with spaces to match
   * the provided min_width. */
  while (i < min_width) {
    to[i++] = ' ';
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

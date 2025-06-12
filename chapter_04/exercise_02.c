#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double s_to_double(const char from[]);

int main(void) {
  char from[] = "42.0e2";

  printf("%f\n", s_to_double(from));

  return EXIT_SUCCESS;
}

double s_to_double(const char from[]) {
  int i;
  int sign;
  int sign_exp;
  double mantissa;
  double exponent;
  double divisor;

  /* Skip leading white-space characters */
  for (i = 0; isspace(from[i]); i++) {
    ;
  }

  /* Parse optional sign */
  sign = (from[i] == '-') ? -1 : 1;
  if (from[i] == '+' || from[i] == '-') {
    i++;
  }
  /* Parse integer part of the number */
  for (mantissa = 0.0; isdigit(from[i]); i++) {
    mantissa = 10.0 * mantissa + (from[i] - '0');
  }
  /* Parse decimal part of the number (if present) */
  if (from[i] == '.') {
    i++;
  }
  for (divisor = 1.0; isdigit(from[i]); i++) {
    mantissa = 10.0 * mantissa + (from[i] - '0');
    divisor *= 10.0;
  }
  /* Parse exponential part of the number (if present) */
  if (from[i] == 'e' || from[i] == 'E') {
    i++;
  }
  sign_exp = (from[i] == '-') ? -1 : 1;
  if (from[i] == '+' || from[i] == '-') {
    i++;
  }
  for (exponent = 0; isdigit(from[i]); i++) {
    exponent = 10 * exponent + (from[i] - '0');
  }

  return sign * (mantissa * pow(10.0, sign_exp * exponent)) / divisor;
}

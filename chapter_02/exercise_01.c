#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("%d\n", SCHAR_MIN);    /* minimum value for signed char */
  printf("%d\n", SCHAR_MAX);    /* maximum value for signed char */
  printf("%d\n", SHRT_MIN);     /* minimum value for signed short int */
  printf("%d\n", SHRT_MAX);     /* maximum value for signed short int */
  printf("%u\n", USHRT_MAX);    /* maximum value for unsigned short int */
  printf("%d\n", INT_MIN);      /* minimum value for signed int */
  printf("%d\n", INT_MAX);      /* maximum value for signed int */
  printf("%u\n", UINT_MAX);     /* maximum value for unsigned int */
  printf("%ld\n", LONG_MIN);    /* minimum value for signed long int */
  printf("%ld\n", LONG_MAX);    /* maximum value for signed long int */
  printf("%lu\n", ULONG_MAX);   /* maximum value for unsigned long int */
  printf("%d\n", CHAR_MIN);     /* minimum value for plain char */
  printf("%d\n", CHAR_MAX);     /* maximum value for plain char */
  printf("%lld\n", LLONG_MIN);  /* minimum value for signed long long int */
  printf("%lld\n", LLONG_MAX);  /* maximum value for signed long long int */
  printf("%llu\n", ULLONG_MAX); /* maximum value for unsigned long long int */
  printf("%e\n", FLT_MIN); /* minimum positive normalized value for float */
  printf("%e\n", FLT_MAX); /* maximum value for float */
  printf("%e\n", DBL_MIN); /* minimum positive normalized value for double */
  printf("%e\n", DBL_MAX); /* maximum value for double */
  printf("%Le\n",
         LDBL_MIN); /* minimum positive normalized value for long double */
  printf("%Le\n", LDBL_MAX); /* maximum value for long double */

  return EXIT_SUCCESS;
};

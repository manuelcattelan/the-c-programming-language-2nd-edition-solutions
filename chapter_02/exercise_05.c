#include <stdio.h>
#include <stdlib.h>

int find_any_char(const char from[], const char chars[]);

int main(void) {
  char from[] = "hello, world!";
  char chars[] = "w";

  printf("%d\n", find_any_char(from, chars));

  return EXIT_SUCCESS;
}

int find_any_char(const char from[], const char chars[]) {
  for (int i = 0; from[i] != '\0'; i++) {
    for (int j = 0; chars[j] != '\0'; j++) {
      if (from[i] == chars[j]) {
        return i;
      }
    }
  }
  return -1;
}

#include <stdio.h>
#include <stdlib.h>

int any(const char s1[], const char s2[]);

int main(void) {
  char s1[] = "hello, world!";
  char s2[] = "w";
  printf("%d\n", any(s1, s2));
  return EXIT_SUCCESS;
}

int any(const char s1[], const char s2[]) {
  for (int s1_idx = 0; s1[s1_idx] != '\0'; s1_idx++) {
    for (int s2_idx = 0; s2[s2_idx] != '\0'; s2_idx++) {
      if (s2[s2_idx] == s1[s1_idx]) {
        return s1_idx;
      }
    }
  }
  return -1;
}

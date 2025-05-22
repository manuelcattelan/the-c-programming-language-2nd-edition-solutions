#include <stdio.h>
#include <stdlib.h>

int any(const char s1[], const char s2[]);

int main(void) {
  char s1[] = "abcdefghijklmnopqrstuvwxyz";
  char s2[] = "abc";
  printf("%d\n", any(s1, s2));
  return EXIT_SUCCESS;
}

int any(const char s1[], const char s2[]) {
  for (int i = 0; s1[i] != '\0'; i++)
    for (int j = 0; s2[j] != '\0'; j++)
      if (s2[j] == s1[i])
        return i;
  return -1;
}

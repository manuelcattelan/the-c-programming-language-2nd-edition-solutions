#include <stdio.h>
#include <stdlib.h>

enum boolean {
  NOT_FOUND, /* current character is not one to delete */
  FOUND      /* current character is one to delete */
};

void squeeze(char s1[], const char s2[]);

int main(void) {
  char s1[] = "abcdefghijklmnopqrstuvwxyz";
  char s2[] = "abc";
  squeeze(s1, s2);
  printf("%s\n", s1);
  return EXIT_SUCCESS;
}

void squeeze(char s1[], const char s2[]) {
  int i, j, k;
  for (i = k = 0; s1[i] != '\0'; i++) {
    /* This variable tracks whether the current character of the given string
     * exists in the string of characters that should be removed from it. */
    int cstatus = NOT_FOUND;
    for (j = 0; s2[j] != '\0'; j++)
      if (s2[j] == s1[i])
        cstatus = FOUND;
    if (cstatus == NOT_FOUND)
      s1[k++] = s1[i];
  }
  s1[k] = '\0';
}

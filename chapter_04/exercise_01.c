#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_last_subs(char from[], char subs[]);

int main(void) {
  char from[] = "hello, world!";
  char subs[] = "l";

  printf("%d\n", find_last_subs(from, subs));

  return EXIT_SUCCESS;
}

int find_last_subs(char from[], char subs[]) {
  int from_len = strlen(from);
  int subs_len = strlen(subs);

  if (subs_len == 0) {
    return -1;
  }

  /* Start iterating from the last possible position where the substring we're
   * looking for could fit. */
  for (int i = from_len - subs_len; i >= 0; --i) {
    int j = 0;
    for (; j < subs_len; ++j) {
      /* As soon as we find a mismatch, we break from the inner for-loop,
       * causing j to not reach the full length of subs. */
      if (from[i + j] != subs[j]) {
        break;
      }
    }
    /* If j has reached the full length of subs, that means all characters in
     * from (starting at position i) were equal to those in subs. */
    if (j == subs_len) {
      return i;
    }
  }
  return -1;
}

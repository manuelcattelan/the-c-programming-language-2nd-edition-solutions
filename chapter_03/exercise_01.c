#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n);

int main(void) {
  int x = 1;
  int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 10;
  printf("%d\n", binsearch(x, v, n));
  return EXIT_SUCCESS;
}

int binsearch(int x, int v[], int n) {
  int l = 0;     /* lower bound for range in which to search for x inside v */
  int h = n - 1; /* upper bound for range in which to search for x inside v */
  int m = (l + h) / 2; /* intermediate index between lower and upper bound */
  while (l <= h && v[m] != x) {
    if (x < v[m])
      h = m - 1;
    else
      l = m + 1;
    m = (l + h) / 2;
  }
  if (v[m] == x)
    return m;
  return -1;
}

/* After measuring the time of execution o this program with the `time` command
 * you can't really notice any difference: both program versions run in under
 * 0.005s most of the times on recent hardware. */

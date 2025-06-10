#include <stdio.h>
#include <stdlib.h>

#define VAL_ARRAY_LEN 10

int binary_search(int target, const int val_array[], int val_array_len);

int main(void) {
  int target = 2;
  int val_array[VAL_ARRAY_LEN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  printf("%d\n", binary_search(target, val_array, VAL_ARRAY_LEN));

  return EXIT_SUCCESS;
}

int binary_search(int target, const int val_array[], int val_array_len) {
  /* Lower bound for range in which to search for x inside v */
  int low = 0;
  /* Upper bound for range in which to search for x inside v */
  int high = val_array_len - 1;
  /* Intermediate index between lower and upper bound */
  int mid = (low + high) / 2;
  while (low <= high && val_array[mid] != target) {
    if (target < val_array[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    mid = (low + high) / 2;
  }
  if (val_array[mid] == target) {
    return mid;
  }
  return -1;
}

/* After measuring the time of execution o this program with the `time` command
 * you can't really notice any difference: both program versions run in under
 * 0.005s most of the times on recent hardware. */

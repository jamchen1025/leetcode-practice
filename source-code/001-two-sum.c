#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
  int* result = (int*)malloc(sizeof(int) * 2);
  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        result[0] = i;
        result[1] = j;
        return result;
      }
    }
  }
  return result;
}

int main() {
  int input[] = {2, 7, 11, 15};
  int len = sizeof(input) / sizeof(int);
  int* r = twoSum(input, len, 9);
  for (int i = 0; i < 2; ++i) {
    printf("%d ", r[i]);
  }
  printf("\n");
  free(r);
  return 0;
}

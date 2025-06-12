#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 1000);  // assume max 1000 results
    int** result = malloc(sizeof(int*) * 1000);

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j < numsSize - 2; j++) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            int left = j + 1, right = numsSize - 1;
            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    int* quad = malloc(sizeof(int) * 4);
                    quad[0] = nums[i]; quad[1] = nums[j]; quad[2] = nums[left]; quad[3] = nums[right];
                    result[*returnSize] = quad;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++; right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return result;
}

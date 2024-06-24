#include <stdio.h>
#include <stdlib.h>

// Function to find two numbers that add up to the target
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Iterate through each element in the array
    for (int i = 0; i < numsSize; i++) {
        // For the current element nums[i], check all the elements after it
        for (int j = i + 1; j < numsSize; j++) {
            // Check if the sum of nums[i] and nums[j] is equal to the target
            if (nums[j] == target - nums[i]) {
                // Allocate memory to store the indices of the two numbers
                int* result = malloc(sizeof(int) * 2);
                // Store the indices in the result array
                result[0] = i;
                result[1] = j;
                // Set returnSize to 2 indicating that we have found a pair
                *returnSize = 2;
                // Return the result array
                return result;
            }
        }
    }
    // In case no such pair is found, set returnSize to 0
    *returnSize = 0;
    // Return NULL indicating no solution
    return NULL;
}

int main() {
    int numsSize, target;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &numsSize);

    int* nums = (int*)malloc(numsSize * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    int returnSize;
    int* indices = twoSum(nums, numsSize, target, &returnSize);

    if (returnSize == 2) {
        printf("Indices: %d, %d\n", indices[0], indices[1]);
        free(indices); // Don't forget to free the allocated memory
    } else {
        printf("No solution found\n");
    }

    free(nums); // Free the memory allocated for the array
    return 0;
}

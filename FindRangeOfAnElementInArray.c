/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main()
{
    int nums[] = { 1,2,3 };
    int size;
    int * result = searchRange(nums, 3, 1, &size);
    printf("\nResult: [%d,%d]", result[0], result[1]);
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int left = 0, right = numsSize - 1, mid = -1, i, flag = 0;
    int* result;
    *returnSize = 2;
    if ((result = (int*)calloc(*returnSize, sizeof(int))) == NULL)
        exit(-1);
    result[0] = result[1] = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            result[0] = result[1] = mid;
            flag = 1;
            break;
        }
        else if (nums[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (flag == 0)
        return result;

    for (i = mid + 1; i < numsSize; i++)
    {
        if (nums[i] != target)
            break;
    }
    result[1] = i - 1;

    for (i = mid - 1; i >= 0; i--)
    {
        if (nums[i] != target)
            break;
    }
    result[0] = i + 1;

    return result;
}
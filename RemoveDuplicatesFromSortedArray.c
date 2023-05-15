/*
 Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize);

int main()
{
    int nums[] = { 1,1,2 };
    int i;
    int k = removeDuplicates(nums, 3);
    for (i = 0; i < k; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}

int removeDuplicates(int* nums, int numsSize)
{
    int i, j, k = 0;
    int change = nums[numsSize - 1] + 1;
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] = change;
            k++;
        }
    }

    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j])
            {
                change = nums[i];
                nums[i] = nums[j];
                nums[j] = change;
            }
        }
    }

    return numsSize - k;
}
/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main()
{
    int nums[] = { 9,1,9,9 };
    int result, i;
    int* ret = plusOne(nums, 4, &result);
    for (i = 0; i < result; i++) {
        printf("%d ", ret[i]);
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i, * ret, flag;
    *returnSize = digitsSize;
    //if all digits are 9
    flag = 1;
    for (i = 0; i < digitsSize; i++)
    {
        if (digits[i] != 9)
            flag = 0;
    }
    if (flag == 1)
    {
        (*returnSize)++;
    }

    if ((ret = (int*)malloc((*returnSize) * sizeof(int))) == NULL)
        exit(-1);

    i = digitsSize - 1;
    while (i >= 0 && digits[i] == 9)
    {
        if (flag == 1)
            ret[i + 1] = 0;
        else
            ret[i] = 0;
        i--;
    }

    if (flag == 1)
    {
        ret[0] = 1;
        return ret;
    }
    else
    {
        ret[i] = digits[i] + 1;
        i--;
        while (i >= 0)
        {
            ret[i] = digits[i];
            i--;
        }
        return ret;
    }
}
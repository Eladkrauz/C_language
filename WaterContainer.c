/*
 You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int maxArea(int* height, int heightSize);

int main()
{
    int arr[] = { 1,8,6,2,5,4,8,3,7 };
    printf("\nRESULT: %d", maxArea(arr, 9));
    return 0;
}

int maxArea(int* height, int heightSize) {
    int i, j, maxArea = 0, area, shorter;
    if (heightSize == 0)
        return 0;
    if (heightSize == 1)
        return height[0];
    
    for (i = 0; i < heightSize - 1; i++)
    {
        for (j = i + 1; j < heightSize; j++)
        {
            shorter = height[i] < height[j] ? height[i] : height[j];
            area = abs(i - j) * shorter;
            if (area > maxArea)
                maxArea = area;
        }
    }

    return maxArea;
}

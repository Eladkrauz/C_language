void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i, first = 0, second = 0, * newArray;
    if ((newArray = (int*)malloc((m + n) * sizeof(int))) == NULL)
        exit(-1);
    else
    {
        for (i = 0; i < m + n; i++)
        {
            if (first >= m)
                newArray[i] = nums2[second++];
            else
                newArray[i] = nums1[first] < nums2[second] ? nums1[first++] : nums2[second++];
        }
        for (i = 0; i < m + n; i++)
        {
            nums1[i] = newArray[i];
        }
    }
}
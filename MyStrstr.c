int strStr(char * haystack, char * needle){
    int i = 0, j = 0, size = strlen(haystack), sizeSub = strlen(needle), flag = 0;
    if (size < sizeSub)
        return -1;
    while (i < size)
    {
        if (haystack[i] != needle[j])
        {
            i++;
            continue;
        }
        else
        {
            flag = 0;
            while (j < sizeSub)
            {
                if (haystack[i + j] != needle[j])
                {
                    flag = 1;
                    break;
                }
                else
                {
                    j++;
                }
            }
            if (flag == 0) //found
            {
                return i;
            }
            else
            {
                j = 0;
                flag = 0;
                i++;
                continue;
            }
        }
    }
    return -1;
}
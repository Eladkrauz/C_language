//Given a string s, find the length of the longest substring without repeating characters.

#include <stdlib.h>
#include <stdio.h>

int lengthOfLongestSubstring(char* s);

int main() {
    char* s = " ";
    printf("The longest substring has %d characters.", lengthOfLongestSubstring(s));
    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int i, j, currentSize = 0, max = 0, size = strlen(s);
    char* sub;
    if (size == 1)
        return 1;
    sub = (char*)malloc(size + 1);
    memset(sub, '\0', size + 1);
    j = 0;
    for (i = 0; i < size; i++)
    {
        //checking if s[i] is already in sub string
        //if it is, reseting the sub string
        if (strchr(sub, s[i]) != NULL)
        {
            currentSize = strlen(sub);
            max = currentSize > max ? currentSize : max;
            j = 0;
            memset(sub, '\0', size + 1);
            i = i - currentSize;
        }
        else //does not exist
        {
            sub[j++] = s[i];
        }
    }
    currentSize = strlen(sub);
    max = currentSize > max ? currentSize : max;
    free(sub);
    return max;
}
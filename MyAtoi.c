/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
*/

int myAtoi(char * s){
    int size = strlen(s), i, neg = 0;
    int spaces = 0, result = 0;
    if (s[0] == ' ')
    {
        while (1)
        {
            spaces++;
            if (s[spaces] != ' ')
                break;
        }
    }

    if (s[spaces] == '-') {
        neg = 1;
        spaces++;
    }
    else if (s[spaces] == '+') {
        neg = 0;
        spaces++;
    }

    for (i = spaces; i < size; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            break;
        else
        {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > 7)) {
                return neg == 1 ? INT_MIN : INT_MAX;
            }
            result = result * 10 + (s[i] - '0');
        }
    }

    return neg == 1 ? (-1) * result : result;
}
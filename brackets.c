/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/

typedef struct Stack {
    char val;
    struct Stack * next;
} Stack;

bool isValid(char * s){
    Stack * head = NULL, *temp;
    int i, size = strlen(s);
    for (i = 0; i < size; i++)
    {
        switch (s[i])
        {
            case '}':
            {
                if (head == NULL || head->val != '{')
                    return false;
                else
                {
                    temp = head;
                    head = head->next;
                    free(temp);
                    break;
                }
            }
            case ']':
            {
                if (head == NULL || head->val != '[')
                    return false;
                else
                {
                    temp = head;
                    head = head->next;
                    free(temp);
                    break;
                }
            }
            case ')':
            {
                if (head == NULL || head->val != '(')
                    return false;
                else
                {
                    temp = head;
                    head = head->next;
                    free(temp);
                    break;
                }
            }
            default:
            {
                if (head == NULL)
                {
                    head = (Stack*)malloc(sizeof(Stack));
                    head->val = s[i];
                    head->next = NULL;
                }
                else
                {
                    temp = (Stack*)malloc(sizeof(Stack));
                    temp->val = s[i];
                    temp->next = head;
                    head = temp;
                }
            }
        }
    }
    return head == NULL;
}
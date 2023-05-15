/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* newList = NULL, *temp1 = list1, *temp2 = list2, *add, *curr = NULL;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    temp1 = list1;
    temp2 = list2;
    curr = newList;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val < temp2->val)
        {
            add = temp1;
            temp1 = temp1->next;
        }
        else
        {
            add = temp2;
            temp2 = temp2->next;
        }
        add->next = NULL;
        if (newList == NULL)
        {
            newList = add;
            curr = add;
        }
        else
        {
            curr->next = add;
            curr = add;
        }
    }
    if (temp1 != NULL)
        curr->next = temp1;
    if (temp2 != NULL)
        curr->next = temp2;
    return newList;
}
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * deleteDuplicates(ListNode *head)
    {
        if(head == NULL)
            return NULL;
        ListNode *cur = head, *next = cur->next;
        while(next!= NULL)
        {
            if(cur->val == next->val)
            {
                //del next 
                cur->next = next->next;
                next = cur->next;
            }
            else
            {
                cur = next;
                next = next->next;
            }
        }
        return head;
    }
};


int main(void)
{
    Solution solution;
    ListNode *head = solution.deleteDuplicates(NULL);
    return 0;
}

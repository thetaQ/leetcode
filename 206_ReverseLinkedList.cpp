#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //solution one: iteratively
    ListNode * reverseList(ListNode *head) 
    {
        ListNode *pre = NULL, *curr = head;
        ListNode *tmp;
        while(curr != NULL)
        {
            tmp = curr->next; 
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        return pre;                
    }
    
    //solution two: recursively
    ListNode * reverseList_2(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *node = reverseList_2(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }

};


int main(void)
{
    Solution solution;
    solution.reverseList(NULL);
    return 0;
}

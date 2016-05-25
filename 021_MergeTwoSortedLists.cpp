#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:

<<<<<<< HEAD
    //Solution one: iterative
=======
    //Solution one: recursive
>>>>>>> origin/master
    ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode *head, *cur;
        if(l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;                        
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        cur = head;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if(l1 == NULL)
        {
           cur->next = l2;
        }
        if(l2 == NULL)
        {
            cur->next = l1;
        }
        return head;
    }
    
    //Solution two: recursive
    ListNode * mergeTwoLists_2(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists_2(l1->next, l2);
            return l1;        
        }
        else
        {
            l2->next = mergeTwoLists_2(l1, l2->next);
            return l2;
        }
    }
};


    
int main(void)
{
    Solution solution;
    ListNode *list = solution.mergeTwoLists(NULL, NULL);
    return 0;
}
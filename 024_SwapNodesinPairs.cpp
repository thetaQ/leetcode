#include <iostream>
using namespace std;

struct ListNode 
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //Solution one: iterative
    ListNode* swapPairs(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
         
        ListNode *cur = head;
        ListNode *new_head = cur->next;
        ListNode *tmp, *last = NULL;
        while(cur != NULL && cur->next != NULL)
        {
            tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = cur;
            if(last != NULL)
                last->next = tmp;
            last = tmp->next;
            cur = cur->next;
        }
        return new_head;
    }
    
    //Solution two: recursive
    ListNode* swapPairs_2(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *next = head->next;
        
        head->next = swapPairs_2(next->next);
        next->next = head;
        return next;
    }
    
};
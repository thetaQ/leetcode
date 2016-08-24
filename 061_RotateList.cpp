#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(head == NULL || k == 0)
            return head;
    
        int length = 0;
        ListNode *ahead = head;
        ListNode *behind = head;
        while(ahead != NULL)
        {
            length ++;
            ahead = ahead->next;
        }
        
        k = k % length;
        ahead = head;
        if(k == 0)
            return head;
        for(int i = 0; i < k; i++)
        {
            ahead = ahead->next;
        }
        while(ahead != NULL && ahead->next != NULL)
        {
            ahead = ahead->next;
            behind = behind->next;
        }
        ListNode *new_head = behind->next;
        ahead->next = head;
        behind->next = NULL;
        return new_head;
    }
};
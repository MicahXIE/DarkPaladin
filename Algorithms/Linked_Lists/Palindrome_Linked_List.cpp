/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Idea:

使用快慢两个指针找到链表中点，慢指针每次前进一步，快指针每次前进两步。
在慢指针前进的过程中，同时修改其 next 指针，使得链表前半部分反序。最后比较中点两侧的链表是否相等。

Flow:

head -> 1 -> 2 -> 2 -> 2 -> 1 -> NULL

NULL <- 1    2 -> 2 -> 2 -> 1 -> NULL
      prev slow  fast

NULL <- 1 <- 2    2 -> 2 -> 1 -> NULL
            prev slow      fast

NULL <- 1 <- 2    2 -> 2 -> 1 -> NULL
            prev      slow  fast
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        if(fast != NULL){
            slow = slow->next;
        }
        
        while(slow != NULL && prev != NULL){
            if(slow->val != prev->val)
                return false;
            slow = slow->next;
            prev = prev->next;
        }
        
        return true;
        
    }
};
/*
Hackerrank Linked Lists: Detect a Cycle

idea:
快慢指针的方法，就是让两个指针同时指向链表。在向后遍历的时候，一个指针每次走两步，称为快指针；
一个指针每次走一步，称为慢指针。如果快慢指针相遇，则说明链表有环，否则无环。

*/

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head == NULL || head->next == NULL){
        return false;
    }
    
    Node* slow = head;
    Node* fast = head->next;
    
    while(slow != fast){
        if(fast == NULL || fast->next == NULL) return false;
        
        slow = slow->next;
        fast = fast->next->next;
        
    }
    
    return true;
}
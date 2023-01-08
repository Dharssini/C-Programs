/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        
        ListNode *temp1 = head;ListNode *temp2 = NULL;  
        if(head==NULL){
            return head;
        }
        if(temp1->next == NULL)
        {
            head = NULL;
            delete temp1;
            return head;
        }
        while (temp1->next!=NULL){
            size++;
            temp1 = temp1->next;            
        }
        temp1 = head;        
        int iteration = (size - n)+1; //5-2 = 3
        
        while(0<iteration--)
        {
            temp2 = temp1;
            temp1 = temp1->next;            
        }
        if(temp1 == head){
            head = temp1->next;
            delete temp1;
            return head;
        }       
        
        temp2->next = temp1->next;
        delete temp1;
       
        return head;
    }
};
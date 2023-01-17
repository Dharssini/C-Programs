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
    ListNode* reverse(ListNode* ptr) {
        ListNode* pre=NULL;
        ListNode* nex=NULL;
        while(ptr!=NULL) {
            nex = ptr->next;
            ptr->next = pre;
            pre=ptr;
            ptr=nex;
        }
        return pre;
    }
    ListNode* find_middle(ListNode* head,int n)
        {
            ListNode *slow=head,*fast=head;
            while(fast!=NULL && fast->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            } 
            if(n&1)
                return slow->next;
            else
                return slow;
        }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        
        ListNode *temp=head;
        // Iterate to count odd/even
        int n=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            n++;
        }
        temp=head;
        // Find the mid elemeny
        ListNode *head_mid=find_middle(temp,n);
        // Reverse the second half linked-list
        ListNode *head_rev=reverse(head_mid);
        // Verify first half and second half of linked-list are equivalent
        while(head_rev!=NULL)
        { 
 
            if(head->val!=head_rev->val)
                return false;
            
            head_rev=head_rev->next;
            head=head->next;
        }
        return true;
    }
};
 /*   bool isPalindrome(ListNode* head) {
        
        if(head==NULL||head->next==NULL) return true;
        
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* temp3 = NULL;
        
        if(temp1->val == temp2->val && temp2->next == NULL) return true; 
        while(temp1->val != temp2->val)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
            if(temp1->next == NULL) return false;
        }
        
        temp2->next = reverse(temp2->next);
        temp2 = temp2->next;
        temp3 = head;
        while(temp2!=NULL)
        {
            if(temp2->val == temp3->val) return true;
            temp2 = temp2->next;
            temp3 = temp3->next; 
        }
        return false;
        
    }
}; */


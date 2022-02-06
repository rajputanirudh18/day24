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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL) return NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
            
        }
        return prev;
        
    }
    ListNode* getMid(ListNode* head)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void print(ListNode* head)
    {
        while(head)
        {
            cout<<head->val<<" ";
            head=head->next;
        }
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid = getMid(head);
        cout<<mid->val;
         mid->next=reverse(mid->next);
        ListNode* start=head;
        ListNode* end=mid->next;
        
        
        while(end!=NULL){
            if(end->val!=start->val) return false;
            start=start->next;
            end=end->next;
        }
        return true;
        
    }
};
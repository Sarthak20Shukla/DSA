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
int gcd(int a,int b){
    int mini=min(a,b);
    for(int i=mini;i>=1;i--){
        if(a %i==0 && b%i==0) {
            return i;
        }
    }
    return 1;
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
       if(head->next==NULL) return head;
               ListNode* temp=head;

        while(temp->next){
        int a=temp->val;
        int b=temp->next->val;
        int x=gcd(a,b);
        ListNode* curr=new ListNode(x);
        curr->next=temp->next;
        temp->next=curr;
        temp=curr->next;
        }
        return head;
    }
};
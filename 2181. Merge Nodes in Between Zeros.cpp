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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*temp=head->next; 
        while(temp && temp->next){
            ListNode*nextNode=temp->next;
            int sum=temp->val;
            while(nextNode && nextNode->val!=0){
                sum+=nextNode->val;
                nextNode=nextNode->next;
            }
            temp->val=sum; 
            temp->next=nextNode->next;
            temp=temp->next;
        }
        return head->next;
    }
};

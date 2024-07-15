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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int>vv; 
        ListNode*temp=head;   
        ListNode*ans=new ListNode(-1),*dummy=ans;

        while(temp){
            vv.push_back(temp->val); 
            temp=temp->next;
        }
        set<int>s(nums.begin(),nums.end()); 
        for(auto&it:vv){
            if(s.count(it)){
                it=0;
            }
        }
        for(auto&it:vv){
            if(it!=0){
                ans->next=new ListNode(it); 
                ans=ans->next;
            }
        }
        return dummy->next;
    }
};

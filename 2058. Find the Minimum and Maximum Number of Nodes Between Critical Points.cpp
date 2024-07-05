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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2,-1); 
        if(head->next->next==NULL) return ans;
        ListNode*temp=head->next;
        ListNode*prev=head; 
        int mn1=1e9,mn2=-1,mx1=0,mx2=-1,mini=1e9;
        int pos=2;
        while(temp->next){
            int curr_val = temp->val ;
            int prev_val = prev->val ; 
            ListNode*nextNode=temp->next; 
            int next_val = nextNode ->val ;
            bool local_max=false,local_min=false;
            if(curr_val>prev_val && curr_val>next_val){
                local_max=true;
            }
            if(curr_val<prev_val && curr_val<next_val){
                local_min=true;
            }
            if(local_max || local_min){
                mn1=min(mn1,pos);
                mx1=max(mx1,pos);
                if(mn2==-1) mn2=pos; 
                else if(mx2==-1) mx2=pos; 
                if(mn2!=-1 && mx2!=-1){
                    mini=min(mini,mx2-mn2); 
                    mn2=mx2;
                    mx2=-1;
                }
              if(local_max==true)  local_max=false;
              if(local_min==true)  local_min=false;
            }
            pos++;
            prev=temp;
            temp=temp->next;
        }
       if(mini==1e9 || mn1==1e9) return ans; 
        ans[1] = mx1-mn1 ; 
        ans[0]=mini;
        return ans;
    }
};

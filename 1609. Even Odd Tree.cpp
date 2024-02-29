/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    bool check(vector<int>&v,int level){
      int n=v.size();
      for(int i=1;i<n;i++){ 
          if(level&1) {  
              if(v[i]%2==1) return 0;
          } 
          else if(level%2==0) { 
             if(v[i]%2==0) return 0;  
          }
      	if(v[i-1]>=v[i]) return 0;
      } 
        if(v.size()>=1){
               if(level&1) return v[0]%2==0;
               else return v[0]%2==1;
         }
     return 1;
    }
    bool isEvenOddTree(TreeNode* root) {
        int level=0;
        queue<TreeNode*>q; 
        if(root) q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>l; 
            while(sz--){
                TreeNode*node = q.front() ;
                l.push_back(node->val); 
                q.pop(); 
                if(node->left){
                    q.push(node->left) ; 
                }
                if(node->right){
                    q.push(node->right) ; 
                }
            } 
            if(level%2==0){
                if(!check(l,level)) return 0;
            }
           else{
                reverse(l.begin(),l.end()) ;
                if(!check(l,level)) return 0;
           }
           level++;
        }
    return 1; 
    }
};

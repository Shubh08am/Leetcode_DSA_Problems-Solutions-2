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
    void solve(TreeNode*root,int &first_min,long long &second_min){
        if(root==NULL) return;
        long long possible_min=1e15;
        if(root->val<possible_min){
            possible_min=root->val; 
            if(second_min>first_min && first_min!=possible_min){
                second_min=min(1ll*second_min,1ll*possible_min);
            }
        }
        solve(root->left,first_min,second_min);
        solve(root->right,first_min,second_min);
    }
    int findSecondMinimumValue(TreeNode* root) {
        //root is the minimum value 
        long long second_min = 1e15 ; 
        solve(root,root->val,second_min);
        return second_min==1e15?-1:second_min;
    }
};

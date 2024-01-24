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
    bool isLeaf(TreeNode*root){
        return !root->left && !root->right;
    }
    bool isPowerOfTwo(int num){
        return ((num&(num-1))==0);
    }
    void solve(TreeNode* root,int &palindromePath,int mask){
        if(!root) return;
        mask=(mask^(1<<(root->val)));
        if(isLeaf(root)){
            if(isPowerOfTwo(mask)){
                palindromePath++;
            }
        }
        solve(root->left,palindromePath,mask);
        solve(root->right,palindromePath,mask);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int palindromePath=0,mask=0;
        solve(root,palindromePath,mask);
        return palindromePath;
    }
};

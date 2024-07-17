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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
         //bfs -> 3 check root,left and child node 
        unordered_set<int>deleteNode(to_delete.begin(),to_delete.end()); 
        queue<TreeNode*>q;
        q.push(root); 
        vector<TreeNode*>forest ; 
        while(!q.empty()){
            TreeNode*node=q.front(); 
            q.pop(); 
             //if node needs to be deleted take its child if present in forest 
            if(deleteNode.count(node->val)){
                if(node->left && !deleteNode.count(node->left->val)) forest.push_back(node->left) ; 
                if(node->right && !deleteNode.count(node->right->val)) forest.push_back(node->right) ; 
            }
            //if left child of node to be deleted 
            if(node->left){
                q.push(node->left) ; 
             if(deleteNode.count(node->left->val))   node->left=NULL;
            } 
            //if right child of node to be deleted 
            if(node->right){
                 q.push(node->right) ;
              if(deleteNode.count(node->right->val))  node->right=NULL;
            }
        }
        if(!deleteNode.count(root->val)) forest.push_back(root) ; 
      return forest;  
    }
};

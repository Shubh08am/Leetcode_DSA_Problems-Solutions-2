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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        //just extra space needed , make a node in a map data structure 
        unordered_map<int,TreeNode*>tree; 
        unordered_set<int>childs;
        for(auto&curr:descriptions){
            int parenti=curr[0],childi=curr[1],isLefti=curr[2] ; 
            if(tree.find(parenti)==tree.end()){
                tree[parenti]=new TreeNode(parenti);
            }
            if(tree.find(childi)==tree.end())   tree[childi]= new TreeNode(childi); 
            if(isLefti){
               tree[parenti]->left=tree[childi];
            }
            else{
                tree[parenti]->right=tree[childi];
            }
            childs.insert(childi);
        } 
        //now, find the root -> who doesn't appear in child 
        for(auto&curr:descriptions){
            int parenti=curr[0]; 
            if(childs.find(parenti)==childs.end()){
                return tree[parenti];
            } 
        }
        return NULL;
    }
};

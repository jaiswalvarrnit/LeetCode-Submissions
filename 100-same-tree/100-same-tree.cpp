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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL) return true;
        if(p == NULL and q != NULL) return false;
        if(p != NULL and q == NULL) return false;
        bool l = isSameTree(p -> left, q -> left); // check if left, right subtree is same
        bool r = isSameTree(p -> right, q -> right);
        
        bool check = p -> val == q -> val; // check whether they have same value
        if(l and r and check) return true;
        
        return false;
    }
};
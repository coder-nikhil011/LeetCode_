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
    int getSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }

    int getCount(TreeNode* root) {
        if (!root) return 0;
        return 1 + getCount(root->left) + getCount(root->right);
    }

    int solve(TreeNode* root){
        if (!root) return 0;
        
        TreeNode* head = root;
        int result = 0;
        
        if (head) {
            int count = 0;
            int sum = head->val + getSum(head->left) + getSum(head->right);
            count = getCount(head);
            int average = sum / count;
            
            if (average == head->val) {
                result++;
            }
            
            count = 0;
        }
        
        return result + solve(root->left) + solve(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        return solve(root);
    }
};

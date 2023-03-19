
using namespace std;

/*
Struct TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this struct.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    
public:
    bool isCompleteTree(TreeNode* root) const {
        return isCompleteBinaryTree(root, 0, countNumberOfTreeNodes(root));
    }
    
private:
    bool isCompleteBinaryTree(TreeNode* root, int index, int numberOfNodes) const {
        if (root == nullptr) {
            return true;
        }
        if (index >= numberOfNodes) {
            return false;
        }
        return isCompleteBinaryTree(root->left, 2 * index + 1, numberOfNodes)
                && isCompleteBinaryTree(root->right, 2 * index + 2, numberOfNodes);
    }

    int countNumberOfTreeNodes(TreeNode* root) const {
        if (root == nullptr) {
            return 0;
        }
        return 1 + countNumberOfTreeNodes(root->left) + countNumberOfTreeNodes(root->right);
    }
};

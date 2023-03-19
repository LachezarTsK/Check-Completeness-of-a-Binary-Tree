
public class Solution {

    public boolean isCompleteTree(TreeNode root) {
        return isCompleteBinaryTree(root, 0, countNumberOfTreeNodes(root));
    }

    private boolean isCompleteBinaryTree(TreeNode root, int index, int numberOfNodes) {
        if (root == null) {
            return true;
        }
        if (index >= numberOfNodes) {
            return false;
        }
        return isCompleteBinaryTree(root.left, 2 * index + 1, numberOfNodes)
                && isCompleteBinaryTree(root.right, 2 * index + 2, numberOfNodes);
    }

    private int countNumberOfTreeNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + countNumberOfTreeNodes(root.left) + countNumberOfTreeNodes(root.right);
    }
}

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

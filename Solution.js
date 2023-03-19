
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isCompleteTree = function (root) {
    return isCompleteBinaryTree(root, 0, countNumberOfTreeNodes(root));
};

/**
 * @param {TreeNode} root
 * @param {number} index
 * @param {number} numberOfNodes
 * @return {boolean}
 */
function isCompleteBinaryTree(root, index, numberOfNodes) {
    if (root === null) {
        return true;
    }
    if (index >= numberOfNodes) {
        return false;
    }
    return isCompleteBinaryTree(root.left, 2 * index + 1, numberOfNodes)
            && isCompleteBinaryTree(root.right, 2 * index + 2, numberOfNodes);
}

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
function  countNumberOfTreeNodes(root) {
    if (root === null) {
        return 0;
    }
    return 1 + countNumberOfTreeNodes(root.left) + countNumberOfTreeNodes(root.right);
}

/*
 Function TreeNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

public class TreeNode {
    int val;
    TreeNode left, right;

    public TreeNode(int val) {
        this.val = val;
        this.left = this.right = null;
    }
}

public class BinaryTreeChecker {

    private TreeNode prev; // To store the previously visited node during in-order traversal

    public boolean isBST(TreeNode root) {
        prev = null;
        return isBSTUtil(root);
    }

    private boolean isBSTUtil(TreeNode node) {
        if (node != null) {
            // Visit left subtree
            if (!isBSTUtil(node.left))
                return false;

            // Check if the current node's value is greater than the previous visited node
            if (prev != null && node.val <= prev.val)
                return false;

            // Update the previous visited node
            prev = node;

            // Visit right subtree
            return isBSTUtil(node.right);
        }
        return true; // Empty tree is a BST
    }

    public static void main(String[] args) {
        BinaryTreeChecker checker = new BinaryTreeChecker();

        // Example usage
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);

        boolean result = checker.isBST(root);
        System.out.println(result); // Output should be true for this example
    }
}

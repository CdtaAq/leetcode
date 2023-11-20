class TreeNode {
    int val;
    TreeNode left, right;

    public TreeNode(int val) {
        this.val = val;
        this.left = this.right = null;
    }
}

public class MorrisTraversal {

    public static void inOrderTraversal(TreeNode root) {
        TreeNode current = root;

        while (current != null) {
            if (current.left == null) {
                // Visit the current node
                System.out.print(current.val + " ");

                // Move to the right subtree
                current = current.right;
            } else {
                // Find the inorder predecessor (rightmost node in the left subtree)
                TreeNode predecessor = current.left;
                while (predecessor.right != null && predecessor.right != current) {
                    predecessor = predecessor.right;
                }

                if (predecessor.right == null) {
                    // Establish the threaded link
                    predecessor.right = current;
                    current = current.left;
                } else {
                    // Break the threaded link
                    predecessor.right = null;

                    // Visit the current node
                    System.out.print(current.val + " ");

                    // Move to the right subtree
                    current = current.right;
                }
            }
        }
    }

    public static void main(String[] args) {
        // Example usage
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);

        // Perform in-order traversal
        inOrderTraversal(root);
    }
}

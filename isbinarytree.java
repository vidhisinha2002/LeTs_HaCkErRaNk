/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node class is defined as follows:
    class Node {
        int data;
        Node left;
        Node right;
     }
*/
    boolean checkBST(Node root) {
        
        return( isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE)); 
    }

    boolean isBST(Node node, int min, int max) { 
        if (node == null)   
	            return true;
	 
        if (node.data < min || node.data > max)   //boundry constraints
            return false;
	 
        return (isBST(node.left, min, node.data-1) &&   //recursively tightening the range for left and right
                    isBST(node.right, node.data+1, max));
   }

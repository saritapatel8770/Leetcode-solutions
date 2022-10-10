/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        
        if(root.left==null && root.right==null) return false;
        
        Set<Integer> set = new HashSet<>();
        getVals(root,set);
        
        for(int i:set){
            if(set.contains(k-i) && i!=k-i) return true;
        }
        
            return false;
    }
    
    void getVals(TreeNode root, Set<Integer> set){
        
        if(root==null) return;
        
        set.add(root.val);
        getVals(root.left,set);
        getVals(root.right,set);
        
    }
    
}
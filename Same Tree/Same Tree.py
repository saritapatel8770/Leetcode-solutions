class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # if the tree ends here -> subtree is equal
        if p==None and q==None:
            return True
         # if sides of the tree don't match -> subtree is different
        if (p==None and q!=None) or (p!=None and q==None) or p.val != q.val:
            return False
        return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)

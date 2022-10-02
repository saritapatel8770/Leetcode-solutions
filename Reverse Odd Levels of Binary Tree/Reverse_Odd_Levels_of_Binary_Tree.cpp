//Solution using Recursion. time Complexity O(n) and Auxiliary space O(n)for recusion call stack here n is no of nodes in given tree.

class Solution {
public:
    void helper(TreeNode* root1,TreeNode* root2,int count){
        if(!root1&&!root2)return;
        
        if(count%2!=0){  //for revere of nodes at odd levels
            int temp=root1->val;
            root1->val=root2->val;
            root2->val=temp;
            
        }
        helper(root1->left,root2->right,count+1);
        helper(root1->right,root2->left,count+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)return NULL;
        if(!root->left&&!root->right)return root;
        int count=1;
        helper(root->left,root->right,count);
        return root;
    }
};


//Iterative Solution using queue data structure time Complexity O(n) and Auxiliary space O(no.of nodes at last level). here n is no of nodes in given tree.
class Solution {
public:
    vector<int> traverse;
    TreeNode* reverseOddLevels(TreeNode* root) {
        bool oddLevel = false;
        auto Root = root;
        queue<TreeNode*> q;
        q.push({root});
        
        while(q.size()) {
            int cnt = q.size();
            vector<int> temp;
            
            while(cnt--) {
                auto node = q.front();
                q.pop();
                
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(oddLevel) {
                reverse(temp.begin(), temp.end());
                for(auto a : temp) traverse.push_back(a);
                oddLevel = false;
            } else {
                for(auto a : temp) traverse.push_back(a);
                oddLevel = true;
            }      
        }
        
        // Create Binary Tree from Vector
        queue<TreeNode*> Q;
        Q.push({Root});
        int j = 1;
        
        while(Q.size() && j < traverse.size()) {
            int cnt = Q.size();
            while(cnt--) {
                auto node = Q.front();
                Q.pop();
                
                if(j < traverse.size()) {
                    node->left = new TreeNode(traverse[j++]);
                }
                if(j < traverse.size()) {
                    node->right = new TreeNode(traverse[j++]);
                }
                if(node->left) {
                    Q.push(node->left);
                }
                if(node->right) {
                    Q.push(node->right);
                }
            }
        }
        return Root;
    }
};


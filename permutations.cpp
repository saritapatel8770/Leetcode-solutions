class Solution {
    void solve(int ind, vector<vector<int>>&ans,vector<int> nums,vector<int>out){
        
        if(ind>=nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int j=ind;j<nums.size();j++){
            swap(nums[ind],nums[j]);
            solve(ind+1,ans,nums,out);
            swap(nums[ind],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>out;
        
        int ind=0;
        solve(ind,ans,nums,out);
        return ans;
        
    }
};

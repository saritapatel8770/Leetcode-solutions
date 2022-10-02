class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp=nums;
        ans.push_back(nums);
        sort(nums.begin(),nums.end());
        do{
            if(nums!=temp)
                ans.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};

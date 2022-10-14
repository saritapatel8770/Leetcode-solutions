#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
void solve(vector<int>& nums, vector<vector<int>>& ans, int index){
    if(index>=nums.size()){
        ans.push_back(nums);
        return;
    }
    
    for(int i=index; i<nums.size(); i++){    
        swap(nums[index],nums[i]);
        solve(nums, ans, index+1);
        swap(nums[index],nums[i]);
    }   
}


public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};

int main()
{
    return 0;
}
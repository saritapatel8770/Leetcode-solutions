class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map <int,int> mp;
        int ans;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
            mx=max(mx,nums[i]);
        }
        for(int i=1;i<mx;i++){
                if(mp[i]!=1){
                    return i;
                }
        }
        return mx+1;
        
    }
};

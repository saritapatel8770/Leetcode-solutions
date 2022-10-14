#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int max_score = 0, curr_score=0, i=0, j=0;
        while(i<n)
        {
            if(mp.count(nums[i]) and mp[nums[i]]>= j) 
            {
                curr_score -= accumulate(nums.begin() + j ,nums.begin() + mp[nums[i]] +1, 0);
                j = mp[nums[i]]+1;
            }
            else 
            {
                curr_score += nums[i];
                mp[nums[i++]]=i;
            }
            max_score = max(max_score,curr_score);
        }
        return max_score;
    }
};

int main()
{
    return 0;
}
class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        
        vector<int>v;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
             
            if(!dq.empty() and dq.front()==i-k)
                dq.pop_front();
            
            while(!dq.empty() and nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i>=k-1)
                v.push_back(nums[dq.front()]);
        }
        return v;
        
    }
};

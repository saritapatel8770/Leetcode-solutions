class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        /*
        The idea is, instead of finding the smallest prefix + suffix array
        we can find the largest array with total sum of (sum(nums) - x)
        This can be done in O(1) time
        */
        int left = 0, right = 0;
        long long total = 0;
        // Get the total
        for (int num: nums){
            total += num;
        }
        total -= x;
        // Sliding window technique
        long long curTot = 0;
        int curL = -1;
        for (; right < nums.size(); right++){
            curTot += nums[right];
            // Set up the window size
            while ((left <= right) && (curTot > total)){
                curTot -= nums[left];
                left++;
            }
            // Update the length iff the current solution length is max
            if (curTot == total){
                if (right - left + 1 > curL){
                    curL = right - left + 1;
                }
            }
        }
        // Return -1 if we could not find the solution
        if (curL == -1){
            return -1;
        }
        return nums.size() - curL;
    }
};

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int maxSum = 0, currSum = 0;
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0, j = 0; i < n;)
        {
            if (st.count(nums[i]))
            {
                st.erase(nums[j]);
                currSum -= nums[j++];
            }
            else
            {
                st.insert(nums[i]);
                currSum += nums[i++];
            }
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
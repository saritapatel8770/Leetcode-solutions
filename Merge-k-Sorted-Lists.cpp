/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        for(auto i : lists)
        {
            ListNode* value = i;
            while(value != NULL)
            {
                nums.push_back(value->val);
                value = value -> next;
            }
        }
        sort(nums.begin(), nums.end());
        if(nums.size() == 0)
            return NULL;
        ListNode* ans = new ListNode(nums[0]);
        ListNode* value = ans;
        for(int i=1; i<nums.size(); i++)
        {
            value -> next = new ListNode(nums[i]);
            value = value -> next;
        }
        return ans;
    }
};

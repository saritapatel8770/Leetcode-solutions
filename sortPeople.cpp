class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string>mp;
        for(int i=0;i<heights.size();i++)
            mp[heights[i]]=names[i];
        vector<string> ans;
        sort(heights.begin(),heights.end());
        for(int i=names.size()-1;i>=0;i--)
            ans.push_back(mp[heights[i]]);
        return ans;
    }
};

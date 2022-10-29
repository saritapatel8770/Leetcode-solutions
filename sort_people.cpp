// Leetcode problem - 2418. Sort the People
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;
        for(int i=0;i<names.size();i++){
            mp[heights[i]]= names[i];
        }
        vector<string> ans, ans1;
        for(auto val:mp){
            ans.push_back(val.second);
        }
        for(int i=names.size()-1;i>=0;i--){
            ans1.push_back(ans[i]);
        
        }
        return ans1;
        
    }
};
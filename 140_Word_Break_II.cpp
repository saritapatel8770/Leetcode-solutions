class Solution {
public:
    
    void f(int i, int j, string s, vector<string>&wordDict, int n, vector<string>&ans, map<string, bool>&m, string &temp) {
        
        if(i>=n && j>=n) {
            ans.push_back(temp);
            return;
        }
        if(j>=n) return;
        string str = s.substr(i, j-i+1);
        if(m.find(str)!=m.end()) {
            string st = temp;
            temp+=str;
            if(j!=n-1) temp+=" ";
            f(j+1, j+1, s, wordDict, n, ans, m, temp);
            temp = st;
        }
        f(i, j+1, s, wordDict, n, ans, m, temp);
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        map <string, bool> m;
        for(int i=0; i<wordDict.size(); i++) m[wordDict[i]]=1;
        vector<string> ans;
        string temp="";
        f(0, 0, s, wordDict, n, ans, m, temp);
        return ans;
    }
};

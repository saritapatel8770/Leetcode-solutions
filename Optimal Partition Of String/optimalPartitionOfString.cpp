class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> mp1;
        
        int result = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(mp1.find(s[i]) != mp1.end())
            {
//                 found element
                i--;
                result++;
                mp1.clear();
                    
            }
            else
            {
                mp1[s[i]] = 1;
            }
        }
        
        return result + 1;
    }
};
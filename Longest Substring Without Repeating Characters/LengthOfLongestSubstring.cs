public class Solution {
    
    // This function returns true if all characters in
    // str[i..j] are distinct, otherwise returns false
public static bool areDistinct(string str, int i, int j)
    {

        // Note : Default values in visited are false
        bool[] visited = new bool[26];

        for(int k = i; k <= j; k++)
        {
            if (visited[str[k] - 'a'] == true)
                return false;

            visited[str[k] - 'a'] = true;
        }
        return true;
    }

    public int LengthOfLongestSubstring(string s) {
        int n = s.Length;
        // Result
        int res = 0;

        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if (areDistinct(s, i, j))
                    res = Math.Max(res, j - i + 1);

        return res;
    }
}
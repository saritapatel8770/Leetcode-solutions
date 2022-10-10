class Solution {
    int dp[][];
    public int minDistance(String word1, String word2) {
        dp = new int[word1.length()+1][word2.length()+1];
        for(int[] temp : dp){
            Arrays.fill(temp,-1);
        }
        
        int common = lcs(word1, word2, word1.length(), word2.length());
        return (word1.length()-common)+(word2.length()-common);
    }
    
    int lcs(String s1, String s2, int len1, int len2){
        if(len1 == 0 || len2 == 0) return 0;
        if(dp[len1][len2] != -1) return dp[len1][len2];
        else {
            if(s1.charAt(len1-1) == s2.charAt(len2-1)){
//                list.add(s1.charAt(len1-1));
                dp[len1][len2] = 1 + lcs(s1,s2, len1 - 1, len2 - 1);
            }
            else{
                dp[len1][len2]=Math.max(lcs(s1,s2,len1-1,len2),lcs(s1,s2,len1,len2-1));
            }

            return dp[len1][len2];
        }
    }
}
class Solution {
    public int minDistance(String word1, String word2) {
        int[][] result = new int[word1.length()][word2.length()];
		for(int[] row : result){
			Arrays.fill(row, -1);
		}
        return helper(word1, word1.length() -1 ,word2, word2.length() -1, result);
        
    }
    private static int helper(String word1, int idx1, String word2, int idx2, int[][] result) {
		if(idx1<0){
			return idx2 +1;
		} else if(idx2<0){
			return idx1 +1;
		}
		if(result[idx1][idx2] == -1){
			if(word1.charAt(idx1) == word2.charAt(idx2)){
				result[idx1][idx2] = helper(word1, idx1-1, word2, idx2-1, result);
			} else{
				result[idx1][idx2] = 1+ Math.min(helper(word1, idx1-1, word2, idx2, result), helper(word1, idx1, word2, idx2 -1, result));
			}
			
		}
		return result[idx1][idx2];
	}
}

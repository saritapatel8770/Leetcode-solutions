public class Solution {
    HashMap<Integer, List<String>> dp = new HashMap<>();

    public List<String> wordBreak(String s, Set<String> wordDict) {
        int maxLength = -1;
        for(String ss : wordDict) maxLength = Math.max(maxLength, ss.length());
        return addSpaces(s, wordDict, 0, maxLength);
    }
    
    private List<String> addSpaces(String s, Set<String> wordDict, int start, int max){
        List<String> words = new ArrayList<>();
        if(start == s.length()) {
            words.add("");
            return words;
        }
        for(int i = start + 1; i <= max + start && i <= s.length(); i++){
            String temp = s.substring(start, i);
            if(wordDict.contains(temp)){
                List<String> ll;
                if(dp.containsKey(i)) ll = dp.get(i);
                else ll = addSpaces(s, wordDict, i, max);
                for(String ss : ll) words.add(temp + (ss.equals("") ? "" : " ") + ss);
            }
            
        }
        dp.put(start, words);
        return words;
    }
}

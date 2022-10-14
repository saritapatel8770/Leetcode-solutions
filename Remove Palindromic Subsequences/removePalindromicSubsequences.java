class Solution {
    public int removePalindromeSub(String s) {
        if(s.isBlank()) return 0;
        
        if(isPalindrome(s)){
            return 1;
        }
        return 2;
    }
    
    boolean isPalindrome(String s) {
        int left=0, right=s.length()-1;
        
        while(left<right) {
            if(s.charAt(left)!=s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}

// Time complexity: O(N)
// Space complexity: O(1)

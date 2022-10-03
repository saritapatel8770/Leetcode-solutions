// Runtime: 1 ms.
// Memory Usage: 41.8 MB.

class Solution {
  private int helper(String s, int start, int end, int shift, char sign){
    int n = 0, maxi = 0, tmp = 0;
    
    for(int i = start; i != end; i += shift){
        tmp++;
        n += s.charAt(i) == sign ? -1 : 1;
          
        if( n == 0) maxi = Math.max(maxi, tmp);
        else if( n < 0 ) n = tmp = 0;
      }
    
      return maxi;
    }
  
  public int longestValidParentheses(String s) {
    return Math.max(helper(s, 0, s.length(), 1, ')'), helper(s, s.length() - 1, -1, -1, '('));    
  }
}

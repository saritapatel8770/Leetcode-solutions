class Solution {
    public int longestValidParentheses(String s) {
        Stack <Integer> index=new Stack();
        index.push(-1); 
        int max=0;
        for(int i=0; i<s.length();i++){
            if(s.charAt(i)=='('){
                index.push(i);
            }else{ 
                index.pop();
                if(!index.isEmpty()){
                    max=Math.max(max,i-index.peek());
                }else{
                    index.push(i);
                     }
            } 
        }
        return max;
    }
}
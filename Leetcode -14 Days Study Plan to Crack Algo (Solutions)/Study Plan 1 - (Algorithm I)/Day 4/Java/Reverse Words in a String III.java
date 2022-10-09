class Solution {
    public String reverseWords(String s) {
        char[] arr = s.toCharArray();
        int i =0;
        for(int j=0;j<arr.length;j++){
            if(arr[j] == ' '){
                swap(arr,i,j-1);
                i = j+1;
            }
            
        }
        swap(arr,i,arr.length-1);
        
        return String.valueOf(arr);
    }
    void swap(char[] arr,int start,int end){
        while(start<end){
            char temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
}
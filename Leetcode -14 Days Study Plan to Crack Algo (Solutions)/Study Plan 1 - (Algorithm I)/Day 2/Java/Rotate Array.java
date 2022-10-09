class Solution {
    public void rotate(int[] nums, int k) {
        
        k %= nums.length;
        
        reverse(nums,0,nums.length-1); // Reverse All Elements : 0 to n-1
        reverse(nums,0,k-1);           // Reverse 0 to k-1
        reverse(nums,k,nums.length-1); // Reverse k to n-1
    }
    
    void reverse(int arr[],int start,int end){
        
        while(start<end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
        
    }
    
}
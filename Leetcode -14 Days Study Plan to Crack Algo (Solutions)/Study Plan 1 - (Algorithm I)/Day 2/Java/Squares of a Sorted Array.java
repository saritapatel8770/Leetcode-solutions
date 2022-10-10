class Solution {
    public int[] sortedSquares(int[] nums) {
     
        int i=0;
        int j = nums.length-1;
        
        if((j+1)%2==1) nums[j/2]*=nums[j/2];
        
        while(i<j){
            nums[i]*=nums[i];
            nums[j]*=nums[j]; 
            i++;
            j--;
        }
        
        Arrays.sort(nums);
        
        return nums;
    }
}
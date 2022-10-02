class Solution {
    public void nextPermutation(int[] nums) {
        
        int infPoint=-1;
        for(int i=nums.length-1;i>0;i--){
            if (nums[i]>nums[i-1]){
                infPoint=i-1;
                break;
            } 
        }        
        
        if (infPoint != -1){
            for(int j=nums.length-1;j>0;j--){
                if (nums[infPoint]<nums[j]){
                    nums[j]+=nums[infPoint];
                    nums[infPoint]=nums[j]-nums[infPoint];
                    nums[j]-=nums[infPoint];
                    break;
                }
            }
        }
        
        for (int i=infPoint+1; i<=infPoint+(nums.length-1-infPoint)/2;i++){
            nums[i]+=nums[nums.length+infPoint-i];
            nums[nums.length+infPoint-i]=nums[i]-nums[nums.length+infPoint-i];
            nums[i]-=nums[nums.length+infPoint-i];
        }
        
    }
}
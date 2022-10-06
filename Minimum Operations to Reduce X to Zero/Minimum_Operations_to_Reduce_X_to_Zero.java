class Solution 
{
   
    public int minOperations(int[] nums, int x) 
    {
        int n=nums.length;
        int start=0;
        long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        sum=sum-x;
        if(sum<0)
        {
            return -1;
        }
        long sum1=0;
        int min=Integer.MAX_VALUE;
      for (int end = 0; end < nums.length; end++) 
        {
            sum1+=nums[end];
             while(sum1>sum)
             {
                 sum1-=nums[start];
                 start++;
             }
            if(sum==sum1)
            {
               min=Math.min(nums.length-(end-start+1),min); 
            }
          
        }
        return min==Integer.MAX_VALUE?-1:min;
    }
}

class Solution {
    public int trap(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int water = 0;
        //initializing
        int leftmaxheight = height[l];
        int rightmaxheight = height[r];
        
        
        while(l<r){//iterating the given array with two pointers
            if(leftmaxheight < rightmaxheight){
                l++;
                leftmaxheight = Math.max(leftmaxheight, height[l]);
                water += leftmaxheight - height[l];
            }
            else{
                r--;
                rightmaxheight = Math.max(rightmaxheight, height[r]);
                water += rightmaxheight - height[r];
            }
            
        }
        
        return water;
    }
}
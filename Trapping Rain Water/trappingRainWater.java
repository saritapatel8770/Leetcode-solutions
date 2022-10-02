class Solution {
    public int trap(int[] height) {
        int total_water = 0;
        int l = 0;
        int r = height.length - 1;
        int left_max = height[l];
        int right_max = height[r];
        
        while(l < r) {
            if (left_max < right_max) {
                l++;
                left_max = Math.max(left_max, height[l]);
                total_water += left_max - height[l];
            } else {
                r--;
                right_max = Math.max(right_max, height[r]);
                total_water += right_max - height[r];
            }
        }
        
        return total_water;
    }
}
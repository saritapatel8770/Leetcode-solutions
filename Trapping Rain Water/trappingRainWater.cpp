class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1,sum=0,mleft=0,mright=0;
        for(int i=0;i<n;i++){
            if(height[left]<height[right]){
                height[left]>=mleft?mleft=height[left]:sum+=(mleft-height[left]);
                left++;
            }
            else{
                height[right]>=mright?mright=height[right]:sum+=(mright-height[right]);
                right--;
            }
        }
        return sum;
    }
};

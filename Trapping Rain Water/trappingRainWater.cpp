// BRUTEFORCE APPROACH

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int pre[n];
        int suf[n];
        pre[0]=height[0];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],height[i]);
        }
        
        suf[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int leftMax=pre[i];int rightMax=suf[i];
            if(leftMax>height[i] && rightMax>height[i]){
                int minm=min(leftMax,rightMax);
                ans=ans+minm-height[i];
            }
        }
        return ans;
    }
};

//OPTIMISED APPROACH

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

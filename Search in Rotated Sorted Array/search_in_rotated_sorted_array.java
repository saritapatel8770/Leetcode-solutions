class Solution {
    public int search(int[] nums, int target) {
        int pivot=pivot(nums);
       return  BinarySearch(nums,pivot,target);
        
    }
    static int pivot(int[] arr){
        int start=0;
        int end=arr.length-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            //4 cases
            if(mid<end && arr[mid]>arr[mid+1]){
                return mid;
            }
            if(mid>start && arr[mid]<arr[mid-1]){
                return mid-1;
            }
            if(arr[mid]<=arr[start]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            
        }
        return -1;
    }
    
    static int BinarySearch(int[] arr,int pivot,int target){
        if(pivot==-1){
            //this means that the array is not rorated so do normal binary search
            return Search(arr,0,arr.length-1,target);
        }
        else{
            //if pivot is found you have to do binary search pn two ascending sorted arrays
            int ans=Search(arr,0,pivot,target);
            if(ans!=-1){
                return ans;
            }
            return Search(arr,pivot+1,arr.length-1,target);
        }
    }
    
    static int Search(int[] arr,int start,int end,int target){
        while(start<=end){
            int m=start+(end-start)/2;
            if(arr[m]==target){
                return m;
            }
            else if(arr[m]<target){
                start=m+1;
            }
            else{
                end=m-1;
            }
        }
        return -1;
    }
}
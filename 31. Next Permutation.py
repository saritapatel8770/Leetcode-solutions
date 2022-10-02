class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        if n==1:
            pass
        else:
            lastPeak  = None
            nextToLastPeak = None
            
            for i in range(1,n):
                if nums[i]>nums[i-1]:
                    lastPeak = i
                    nextToLastPeak = i-1
            
            if lastPeak == None:
                nums[:] = nums[::-1]
            else:
                index = lastPeak
                for i in range(lastPeak,n):
                    if nums[nextToLastPeak]<nums[i]<nums[lastPeak]:
                        index = i
                nums[nextToLastPeak],nums[index] = nums[index],nums[nextToLastPeak]
                nums[lastPeak:] = sorted(nums[lastPeak:])

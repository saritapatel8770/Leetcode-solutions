class Solution:
    def combinationSum2(self, nums, target):
            def bt(tlist, start, target):
                s = sum(tlist)
                if s == target:
                    res.append(tlist[::])
                    return
                if s > target:
                    return

                for i in range(start, len(nums)):
                    if i > start and nums[i] == nums[i - 1]:
                        continue
                    tlist.append(nums[i])
                    bt(tlist, i + 1, target)
                    tlist.pop()
            nums.sort()
            res = []
            bt([], 0, target)
            return res

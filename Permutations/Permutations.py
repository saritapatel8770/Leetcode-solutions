class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        results = []
        subset = []

        def dfs():
            if len(subset) == n:
                results.append(subset.copy())
                return

            for num in nums:
                if num not in subset:
                    subset.append(num)
                    dfs()
                    subset.pop()

        dfs()
        return results
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        memo = [[-1] * len(triangle) for _ in range(len(triangle))]
        def dfs(i, j):
            if i == len(triangle):
                return 0
            if memo[i][j] != -1:
                return memo[i][j]

            lower_left = triangle[i][j] + dfs(i + 1, j)
            lower_right = triangle[i][j] + dfs(i + 1, j + 1)
            memo[i][j] = min(lower_left, lower_right)
            return memo[i][j]

        return dfs(0, 0)
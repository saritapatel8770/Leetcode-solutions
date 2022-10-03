



//1. Recursion


 // Recursion *** Will Give TLE ***

 
	int solve(int i, int j, int n, vector<vector<int>>&triangle) {
		if(i == n - 1)
			return triangle[i][j];
		int bottom = triangle[i][j] + solve(i+1, j, n, triangle);
		int  bottom_right = triangle[i][j] + solve(i+1, j+1, n, triangle);
		return min(bottom, bottom_right);
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		return solve(0, 0, n, triangle);
	}


//2. Memoization


 // Memoization
	int solve(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp) {
		if(i == n - 1)
			return triangle[i][j];
		if(dp[i][j] != -1)
			return dp[i][j];
		int bottom = triangle[i][j] + solve(i+1, j, n, triangle, dp);
		int  bottom_right = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);
		return dp[i][j] = min(bottom, bottom_right);
	}
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
		return solve(0, 0, n, triangle, dp);
	
    }


// 3. Tabulation

 // Tabulation
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++) 
			dp[n-1][i] = triangle[n-1][i];
		for(int i = n-2; i >= 0; i--) {
			for(int j = i; j >= 0; j--) {
				int up = triangle[i][j] + dp[i+1][j];
				int up_left = triangle[i][j] + dp[i+1][j+1];
				dp[i][j] = min(up, up_left);
			}
		}
		return dp[0][0];
	}


//4. Space Optimal

// Space Optimization
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int>next(n);
		for(int i = n-1; i >= 0; i--) {
			vector<int>curr(n);
			for(int j = i; j >= 0; j--) {
				if(i == n-1)
					curr[j] = triangle[i][j];
				else {
					int up = triangle[i][j] + next[j];
					int up_left = triangle[i][j] + next[j+1];
					curr[j] = min(up, up_left);
				}
			}
			next = curr;
		}
		return next[0];
	}






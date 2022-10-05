vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
{
    int n = grid.size();
    int m = grid[0].size();
    //          MAKE DP TO CHECK THAT WE DO NOT REVISIT THE SAME INDEX
    //          IF WE VISIT THAT  INDEX WE MAKE IT TRUE
    vector<vector<int>> dp(n, vector<int>(m, 0));

    int array1[4] = {0, 0, 1, -1};
    int array2[4] = {1, -1, 0, 0};

    //         IN THIS ARRAY WE STORE
    //      ({DISTANCE , PRICE , ROW INDEX , COLUM INDEX })
    vector<vector<int>> v;
    int distance = 0;
    queue<pair<int, int>> q;
    //         PUSH STARTING INDEX IN QUEUE
    q.push(make_pair(start[0], start[1]));
    int xx = start[0];
    int yy = start[1];
    //         CHECKING IF WE PUSH STARING INDEX IN OUR VECTOR
    if (xx >= 0 && yy >= 0 && xx < n && yy < m && dp[xx][yy] == 0 && grid[xx][yy] >= pricing[0] && grid[xx][yy] <= pricing[1])
    {

        v.push_back({0, grid[xx][yy], xx, yy});
    }
    //         MAKING OUR STARTING INDEX TRUE IN OUT DP ARRAY
    dp[start[0]][start[1]] = 1;

    //          SIMPLE BFS AND CHECKING THE SAME CONDITION THAT WE CHECK FOR OUR STARTING INDEX
    while (!q.empty())
    {
        distance += 1;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int x = a + array1[j];
                int y = b + array2[j];
                //                   CONDTION CHECK
                if (x >= 0 && y >= 0 && x < n && y < m && dp[x][y] == 0 && grid[x][y] >= pricing[0] && grid[x][y] <= pricing[1])
                {

                    q.push(make_pair(x, y));
                    dp[x][y] = 1;
                    v.push_back({distance, grid[x][y], x, y});

                    //       IF OUR CONDITION IS FAIL
                    //          IF NOT VISITED  AND GRID[X][Y] IS NOT EQUAL TO ZERO THAN WE MOVE TO THAT INDEX, THAT'S WHY WE PUSH IT IN QUEUE BUT NOT IN OUR VECTOR v
                }
                else if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 0 && dp[x][y] == 0)
                {

                    dp[x][y] = 1;
                    q.push(make_pair(x, y));
                }
            }
        }
    }

    vector<vector<int>> ans;
    //          sort our vector v to get our minimum ans  according to question conditions
    sort(v.begin(), v.end());

    int tt = v.size();

    int p = min(k, tt);
    for (int i = 0; i < p; i++)
    {
        ans.push_back({v[i][2], v[i][3]});
    }

    return ans;
}
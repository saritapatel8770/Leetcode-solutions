using heapType = pair<pair<int, int>, pair<int, int>>;

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        // support variables
        int qLen = 1, val, x, y, maxX = grid[0].size() - 1, maxY = grid.size() - 1, dist = -1;
        queue<pair<int, int>> q{{{start[1], start[0]}}};
        priority_queue<heapType, vector<heapType>> best;
        // BFS routine
        while (qLen && best.size() < k) {
            // exploring the current layer
            while (qLen--) {
                // getting the current point and popping it out of q
                auto curr = q.front();
                x = curr.first, y = curr.second;
                q.pop();
                val = grid[y][x];
                // moving out if we already visited this one
                if (val == -1) continue;
                // marking as visited
                grid[y][x] = -1;
                // updating the k best
                if (val >= pricing[0] && val <= pricing[1]) {
                    best.push({{dist, val}, {y, x}});
                    if (best.size() > k) {
                        best.pop();
                    }
                }
                // preparing q for the next run
                if (x && grid[y][x - 1] > 0) q.push({x - 1, y});
                if (y && grid[y - 1][x] > 0) q.push({x, y - 1});
                if (x < maxX && grid[y][x + 1] > 0) q.push({x + 1, y});
                if (y < maxY && grid[y + 1][x] > 0) q.push({x, y + 1});
            }
            // updating distance and q to check if we still need to run and in case with how many elements
            dist++;
            qLen = q.size();
        }
        // creating and populating res
        val = best.size() - 1;
        vector<vector<int>> res(best.size());
        while (best.size()) {
            res[val--] = {best.top().second.first, best.top().second.second};
            best.pop();
        }
        return res;
    }
};

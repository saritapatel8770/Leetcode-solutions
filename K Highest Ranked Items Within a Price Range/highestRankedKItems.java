class Solution {
    public List<List<Integer>> highestRankedKItems(int[][] grid, int[] range, int[] start, int k) {
        int n=grid.length, m=grid[0].length;
        boolean vis[][] = new boolean[n][m];
        int dir[] = new int[]{0, 1, 0, -1, 0};
        Queue<int[]> q = new LinkedList<>();
        q.offer(start);
        vis[start[0]][start[1]]=true;
        List<int[]> candidate = new ArrayList<>(); // if in [lower, upper] add to list
        int dist=0;
        while(!q.isEmpty()){
            int size = q.size();
            while(size --> 0){
                int p[] = q.poll();
                int val = grid[p[0]][p[1]];
                if(val > 1 && range[0] <= val && val <= range[1]){ // if value is valid
                    candidate.add(new int[]{p[0], p[1], dist});
                }
                for(int d=0; d<4; d++){ // check all 4 directions
                    int x = p[0] + dir[d];
                    int y = p[1] + dir[d+1];
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y] != 0 && !vis[x][y]){ // if (x, y) is valid
                        vis[x][y] = true;
                        q.add(new int[]{x, y});
                    }
                }
            }
            dist++;
        }
        Collections.sort(candidate, (a, b) ->{
            if(a[2] != b[2]) return Integer.compare(a[2], b[2]); // check distance
            int price1=grid[a[0]][a[1]]; 
            int price2=grid[b[0]][b[1]];
            if(price1 != price2) return Integer.compare(price1, price2); // price
            if(a[0] != b[0]) return Integer.compare(a[0], b[0]); // rows
            return Integer.compare(a[1], b[1]); // columns
        });
        List<List<Integer>> res = new ArrayList<>();
        for(int i=0; i<candidate.size() && k --> 0; i++){ // take atmost k value as result
            int p[]=candidate.get(i);
            List<Integer> temp = new ArrayList<>();
            temp.add(p[0]);temp.add(p[1]);
            res.add(temp);
        }
        return res;
    }
}
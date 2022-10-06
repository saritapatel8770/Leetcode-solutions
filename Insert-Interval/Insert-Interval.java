 class Solution 
{
    public int[][] insert(int[][] intervals, int[] newInterval) 
    {
        int n = intervals.length;
        List<int[]> r = new ArrayList();

        for (int[] inter : intervals)
        {
            if (is_overlap(inter, newInterval))
            {
                newInterval[0] = Math.min(newInterval[0], inter[0]);
                newInterval[1] = Math.max(newInterval[1], inter[1]);
            }
            else
            {
                r.add(inter);
            }
        }
        
        r.add(newInterval);
        int[][] t = new int[r.size()][2];
        for (int i = 0; i < t.length; ++i) t[i] = r.get(i);
        Arrays.sort(t, (a, b) -> a[0] - b[0]);
        return t;
    }
    
    boolean is_overlap(int[] a, int[] b)
    {
        return !(a[1] < b[0] || a[0] > b[1]);
    }
}

    
    

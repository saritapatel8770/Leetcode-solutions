import java.util.*;

public class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        LinkedList<int[]> mergedIntervals = new LinkedList<>();
        boolean inserted = false;

        for (int[] interval : intervals) {
            if (!inserted && newInterval[0] < interval[0]) {
                mergeInterval(mergedIntervals, newInterval);
                inserted = true;
            }
            mergeInterval(mergedIntervals, interval);
        }

        if (!inserted) {
            mergeInterval(mergedIntervals, newInterval);
        }

        return mergedIntervals.toArray(new int[mergedIntervals.size()][]);
    }

    private void mergeInterval(LinkedList<int[]> mergedIntervals, int[] interval) {
        if (mergedIntervals.isEmpty() || mergedIntervals.getLast()[1] < interval[0]) {
            mergedIntervals.add(interval);
        } else {
            mergedIntervals.getLast()[1] = Math.max(mergedIntervals.getLast()[1], interval[1]);
        }
    }
}
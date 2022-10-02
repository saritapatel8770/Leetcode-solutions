
//importing the required package
import java.util.*;

public class firstMissingPositive {

    // creating the function for leetcode
    public static int firstMissingPositiveNumber(int[] nums) {

        // sorting the given array to arrange them in ascending order.
        Arrays.sort(nums);

        // declaring the required values
        int miss = 1;
        int n = nums.length;

        // checking for the missing number
        for (int i = 0; i < n; i++) {
            if (nums[i] > miss)
                return miss;
            if (nums[i] == miss)
                miss++;
        }
        return miss;
    }

    // main function
    public static void main(String[] args) {
        int[] arr1 = { 3, 4, -1, 1 };
        int ans = firstMissingPositiveNumber(arr1);
        System.out.println(ans);
    }
}
class Solution {
    public void nextPermutation(int[] A) {
        int N = A.length;
        int i;
        int j;

        for (i = N - 2; i >= 0; i--) {
            if (A[i] < A[i + 1])
                break;
        }

        if (i >= 0) {
            for (j = N - 1; j > i; j--) {
                if (A[i] < A[j])
                    break;
            }
            swap(A, i, j);
        }
        reverse(A, i + 1, N - 1);
    }

    private void reverse(int[] A, int start, int end) {
        while (start < end) {
            swap(A, start++, end--);
        }
    }

    private void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

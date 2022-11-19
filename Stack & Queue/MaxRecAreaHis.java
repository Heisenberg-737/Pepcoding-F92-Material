import java.util.Stack;

public class MaxRecAreaHis {

    public static int MaxAreaHis(int[] height) {
        int maxArea = 0;
        Stack<Integer> st = new Stack<>();

        st.push(-1);

        int i = 0;

        while (i < height.length) {
            while (st.peek() != 0 && height[st.peek()] >= height[i]) {
                int ht = height[st.pop()];
                int area = ht * (i - st.peek() - 1);
                maxArea = Math.max(maxArea, area);
            }

            st.push(i);
            i++;
        }

        while (st.peek() != -1) {
            int ht = height[st.pop()];
            int area = ht * (i - st.pop() - 1);
            maxArea = Math.max(maxArea, area);
        }

        return maxArea;
    }

    public static void main(String[] args) {
        int[] arr = { 6, 2, 5, 5, 5, 5, 4, 5, 1 };

        System.out.println("Answer Is:" + MaxAreaHis(arr));
    }

    public static int maxAreaInMaxtrix(char[][] arr) {
        if (arr.length == 0)
            return 0;

        int[] ar = new int[arr[0].length];

        int max_ = 0;

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++)
                ar[j] = (arr[i][j] == '0' ? 0 : ar[j] + 1);

            max_ = Math.max(max_, MaxAreaHis(ar));
        }

        return max_;
    }
}
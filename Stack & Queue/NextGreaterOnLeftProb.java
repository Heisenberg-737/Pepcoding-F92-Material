import java.util.Stack;

public class NextGreaterOnLeftProb {

    public static void nge(int[] arr) {

        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < arr.length; i++) {
            while (st.size() != 0 && st.peek() <= arr[i])
                st.pop();

            if (st.size() == 0)
                System.out.println(arr[i] + "->" + "-1");
            else
                System.out.println(arr[i] + "->" + st.peek());

            st.push(arr[i]);

        }
    }

}